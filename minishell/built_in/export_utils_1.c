/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:37:56 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:42 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	boolerv4(char *name, char *str)
{
	char	*s;
	char	*s1;

	s = ft_substr(str, 11, get_eq(str) - 11);
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

int	booler(t_data *data, char *str)
{
	char	*s;
	char	*s1;

	s = ft_substr(str, 11, get_eq(str) - 11);
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

int	check_list(t_data *data)
{
	t_export	*tmp;
	int			i;

	tmp = data->exp;
	while (tmp)
	{
		i = get_eq(tmp->data);
		if (booler(data, tmp->data) == 1)
		{
			if (check_eq(data) == 1)
			{
				free(tmp->data);
				data->svalx = ft_strjoin3(data->val, '"');
				data->namex = ft_strjoin2('"', data->svalx);
				data->sx = ft_strjoin(data->name, data->namex);
				tmp->data = ft_strjoin("declare -x ", data->sx);
				free(data->svalx);
				free(data->namex);
				free(data->sx);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_eq(t_data *data)
{
	int	i;

	i = -1;
	if (!data->name)
		return (0);
	while (data->name[++i])
	{
		if (data->name[i] == '=')
			return (1);
	}
	return (0);
}

char	*ft_split_join(char **cmd)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		i;

	i = -1;
	s3 = ft_strdup("");
	while (cmd[++i])
	{
		if (cmd[i + 1] == NULL)
			s1 = ft_strdup(cmd[i]);
		else
			s1 = ft_strjoin(cmd[i], " ");
		s2 = ft_strdup(s3);
		free(s3);
		s3 = ft_strjoin(s2, s1);
		free(s1);
		free(s2);
	}
	return (s3);
}
