/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:35:10 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:48 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	boolerv3(char *name, char *str)
{
	char	*s;
	char	*s1;

	s = ft_substr(str, 0, get_eq(str));
	s1 = ft_substr(name, 0, get_eq(name));
	if (ft_strcmp(s, s1) == 0)
	{
		free(s);
		free(s1);
		return (1);
	}
	free(s);
	free(s1);
	return (0);
}

int	booler2(t_data *data, char *str)
{
	char	*s;
	char	*s1;

	s = ft_substr(str, 0, get_eq(str));
	s1 = ft_substr(data->name, 0, get_eq(data->name));
	if (ft_strcmp(s, s1) == 0)
	{
		free(s);
		free(s1);
		return (1);
	}
	free(s);
	free(s1);
	return (0);
}

int	check_list2(t_data *data)
{
	t_env	*tmp;
	int		i;

	tmp = data->enva;
	while (tmp)
	{
		i = get_eq(tmp->data);
		if (booler2(data, tmp->data) == 1)
		{
			if (check_eq(data) == 1)
			{
				free(tmp->data);
				tmp->data = ft_strjoin(data->name, data->val);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	get_eq(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void	get_val2(t_data *data, int i, int j, char *str)
{
	int		l;
	char	*s1;
	char	*s2;

	l = -1;
	while (str[++l])
	{
		if (str[l] == '=')
			break ;
	}
	if (data->val)
		free(data->val);
	if (data->name)
		free(data->name);
	if (str[l] == '=')
	{
		s1 = ft_substr(str, l + 1, ft_strlen(str));
		s2 = val_change(s1, data);
		data->val = ft_strdup(s2);
		free(s2);
	}
	else
		data->val = ft_substr(str, i + 1, (j - 1) - i);
	data->name = ft_substr(str, 0, l + 1);
}
