/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:39:51 by sayar             #+#    #+#             */
/*   Updated: 2022/04/10 21:36:09 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_parsing(char **str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (str[++i])
	{
		k = 0;
		while (str[i][k])
		{
			if (str[i][k] == 34 || str[i][k] == 39)
				j++;
			if (j % 2 != 0)
			{
				if (str[i][k] == '>' || str[i][k] == '<')
					str[i][k] = (char)(-str[i][k]);
			}
			k++;
		}
	}
}

void	ft_change(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			j++;
		if (j > 0)
		{
			if (str[i] == '|')
				str[i] = (char)(-str[i]);
			if (j == 2)
				j = 0;
		}
	}
}

int	check_doc(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '<' && str[i + 1] == '<')
			return (1);
	return (0);
}

void	free_pdir(char **pdir)
{
	int	i;

	i = -1;
	while (pdir[++i])
		free(pdir[i]);
	free(pdir);
}
