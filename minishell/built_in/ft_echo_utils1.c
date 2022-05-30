/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:09:36 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:55 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	alloc_next_len(const char *arg, int ret, t_data *data)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (arg[++i])
	{
		if (arg[i] == -36)
		{
			i++;
			if ((arg[i] == '\0' || ft_isalnum(arg[i]) == 0))
				size++;
			else
				size += ft_str_len(arg, i, data, ret);
			if (ft_isdigit(arg[i]) == 0)
			{
				while (arg[i + 1] && if_char(arg[i]))
					i++;
			}
			else
				size--;
		}
		size++;
	}
	return (size);
}

char	*get_env_value(const char *arg, int pos, t_data *data)
{
	char	var_name[BUFF_SIZE];
	char	*var_value;
	int		i;

	i = 0;
	if (arg[pos] == '?')
	{
		var_value = ft_itoa(t_v.codestatus);
		return (var_value);
	}
	if (ft_isdigit(arg[pos]))
		return (NULL);
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
	free(data->sx);
	return (var_value);
}

static int	env_cpy(char *new_arg, const char *env_value, int pos)
{
	int		i;

	i = 0;
	while (env_value[i])
		new_arg[pos++] = env_value[i++];
	return (i);
}

static void	set_dollar_env(t_cmd *ex, char *arg, t_data *data)
{
	char	*env_value;

	env_value = get_env_value(arg, ex->j, data);
	if (data->echohere == 1)
		env_value = clean_space(env_value);
	if (env_value)
		ex->i += env_cpy(ex->new_arg, env_value, ex->i);
	else
		ex->i += 0;
	ft_memdel(env_value);
	if (arg[ex->j] == '?')
		ex->j++;
	if (ft_isdigit(arg[ex->j]) == 0)
	{
		while (if_char(arg[ex->j]) == 1)
			ex->j++;
	}
}

char	*ft_environment(char *arg, t_data *data, int ret)
{
	t_cmd	ex;
	int		new_arg_len;

	new_arg_len = alloc_next_len(arg, ret, data);
	ex.new_arg = malloc(sizeof(char) * new_arg_len + 1);
	ex.i = 0;
	ex.j = 0;
	while (ex.i < new_arg_len && arg[ex.j])
	{
		while (arg[ex.j] == -36)
		{
			ex.j++;
			if ((arg[ex.j] == '\0' || ft_isalnum(arg[ex.j]) == 0)
				&& arg[ex.j] != '?')
				ex.new_arg[ex.i++] = '$';
			else
				set_dollar_env(&ex, arg, data);
		}
		ex.new_arg[ex.i++] = arg[ex.j++];
	}
	ex.new_arg[ex.i] = '\0';
	return (ex.new_arg);
}
