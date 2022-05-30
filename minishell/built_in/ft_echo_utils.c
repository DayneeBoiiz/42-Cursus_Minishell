/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:32:15 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:52 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	if_char(int c)
{
	if (ft_isalnum(c) == 1 || c == '_')
		return (1);
	return (0);
}

int	ret_size(int ret)
{
	char	*tmp;
	int		ret_len;

	tmp = ft_itoa(ret);
	ret_len = ft_strlen(tmp);
	return (ret_len);
}

int	ft_str_len(const char *arg, int pos, t_data *data, int ret)
{
	char	var_name[BUFF_SIZE];
	char	*var_value;
	int		i;

	i = 0;
	if (arg[pos] == '?')
		return (ret_size(ret));
	if (ft_isdigit(arg[pos]))
		return (0);
	while (arg[pos] && if_char(arg[pos]) == 1 && i < BUFF_SIZE)
	{
		var_name[i] = arg[pos];
		pos++;
		i++;
	}
	var_name[i] = '\0';
	data->sx = ft_strdup(var_name);
	data->sx1 = ft_strjoin("$", data->sx);
	var_value = dollar_line(data->sx1, data);
	i = ft_strlen(var_value);
	free(var_value);
	free(data->sx);
	return (i);
}

int	checkmoney(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 39)
			return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			return (1);
	}
	return (0);
}

void	type_arg(t_token *token, int separator)
{
	if (ft_strcmp(token->str, "") == 0)
		token->type = EMPTY;
	else if (ft_strcmp(token->str, ">") == 0 && separator == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->str, ">>") == 0 && separator == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->str, "<") == 0 && separator == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->str, "|") == 0 && separator == 0)
		token->type = PIPE;
	else if (ft_strcmp(token->str, ";") == 0 && separator == 0)
		token->type = END;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}
