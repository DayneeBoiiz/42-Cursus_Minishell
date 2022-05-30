/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:19:54 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/06 16:41:28 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getdir(t_data *data)
{
	char	**pdir;
	int		i;

	pdir = ft_split(data->pwd, '/');
	i = 0;
	while (pdir[i + 1])
		i++;
	if (ft_strcmp(data->pwd, "/") == 0)
	{
		if (data->dir)
			free(data->dir);
		data->dir = ft_strdup("/");
	}
	else
	{
		if (data->dir)
			free(data->dir);
		data->dir = ft_strdup(pdir[i]);
	}
	free_pdir(pdir);
	return (data->dir);
}

int	ft_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 32)
			i++;
		else if (input[i] != 32)
			return (1);
	}
	return (0);
}

int	checkquotes(char *str)
{
	int	j;
	int	i;

	j = 0;
	i = -1;
	while (str[++i])
		if (str[i] == 34 || str[i] == 39)
			j++;
	return (j);
}
