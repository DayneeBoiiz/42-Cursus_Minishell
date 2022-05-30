/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:32:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:07:50 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_export	*all_export1(t_data *data, t_export *tmp)
{
	tmp->next = malloc(sizeof(struct s_export));
	tmp = tmp->next;
	data->sx = ft_strjoin3(data->val, '"');
	data->sx1 = ft_strjoin2('"', data->sx);
	data->sx2 = ft_strjoin(data->name, data->sx1);
	tmp->data = ft_strjoin("declare -x ", data->sx2);
	tmp->next = NULL;
	free(data->sx);
	free(data->sx1);
	free(data->sx2);
	return (tmp);
}

void	set_dollar(char *str, t_data *data)
{
	if (str[0] == '$')
		str = dollar_line(str, data);
}

void	all_export2(t_data *data, t_export *tmp, int i)
{
	while (tmp->next)
		tmp = tmp->next;
	i = 0;
	while (data->phx[++i])
	{
		set_dollar(data->phx[i], data);
		if (expo_checker(data->phx[i]) != 0)
		{
			data->msg = data->phx[i];
			ft_strerror(data, expo_checker(data->phx[i]));
			break ;
		}
		get_val(data, data->phx[i]);
		if ((check_eq(data) == 1) && (check_list(data)) == 0)
			tmp = all_export1(data, tmp);
		else if (check_eq(data) == 0 && (check_list(data)) == 0)
		{
			tmp->next = malloc(sizeof(struct s_export));
			tmp = tmp->next;
			tmp->data = ft_strjoin("declare -x ", data->name);
			tmp->next = NULL;
		}
		if (check_list2(data) == 0)
			all_env(data);
	}
}

void	space_line2(char *line)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[++i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			j++;
			while (line[i] == '\"' || line[i] == '\'')
				i++;
		}
		if (j % 2 == 0)
		{
			if (line[i] == ' ')
				line[i] = -32;
		}
	}
}

void	all_export(char *input, t_data *data)
{
	t_export	*tmp;
	char		*input1;
	int			i;

	i = 0;
	tmp = data->exp;
	input1 = ft_strdup(input);
	space_line2(input1);
	data->phx = ft_split(input1, -32);
	if (data->phx[1] == NULL)
	{
		while (tmp)
		{
			printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
	}
	else
		all_export2(data, tmp, i);
	free(input1);
	free_pdir(data->phx);
}
