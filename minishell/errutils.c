/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:48:28 by sayar             #+#    #+#             */
/*   Updated: 2022/04/09 13:42:51 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_str(char *str, int i, int j, int k)
{
	while (str[++i])
	{
		if (str[i] == 39)
			j++;
		if (str[i] == 34)
			k++;
		if (k % 2 == 0 && j % 2 == 0)
		{
			if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
				return (1);
			if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
				return (1);
			if (str[i] == '<' && str[i + 1] == '>')
				return (1);
			if (str[i] == '>' && str[i + 1] == '<')
				return (1);
			if (str[i] == '|' && str[i + 1] == '|')
				return (1);
			if (str[i] == 92 || str[i] == ';')
				return (1);
		}
	}
	return (0);
}

int	str_check(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 32)
			i++;
		if (str[i] != 32 && str[i] != '|')
			break ;
		if (str[i] == '|')
			return (1);
	}
	return (0);
}

int	ft_llol(int k, int j, char *str, int i)
{
	i = -1;
	k = 0;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 39)
			j++;
		if (str[i] == 34)
			k++;
	}
	if (k % 2 != 0)
		return (1);
	if (j % 2 != 0)
		return (1);
	return (0);
}

char	*xqoutes2(char *str1, int j, int i)
{
	while (str1[++i])
	{
		if (str1[i] == 32)
			str1[i] = -32;
		if (str1[i] == 34 || str1[i] == 39)
		{
			j++;
		}
		if (j % 2 != 0 && j != 0)
		{
			while (str1[++i])
			{
				if (str1[i] == 34 || str1[i] == 39)
				{
					j++;
					break ;
				}
			}
		}
	}
	return (str1);
}

char	*quotesremove_mini2(char *str)
{
	char	*str1;
	int		i;
	int		j;

	str1 = ft_strdup(str);
	free(str);
	i = -1;
	j = 0;
	return (xqoutes2(str1, j, i));
}
