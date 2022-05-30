/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:13 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/10 21:04:44 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redi(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '>')
			return (1);
		if (str[i] == '<')
			return (2);
	}
	return (0);
}

char	*quotesremove2(char *str)
{
	char	*str1;
	int		i;

	str1 = ft_strdup(str);
	i = -1;
	while (str1[++i])
		if (str1[i] == 34 || str1[i] == 39)
			str1[i] = 32;
	return (str1);
}

void	xquotesremove(char *str1, int i, int j)
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

char	*quotesx2(char *str1, int i, int j)
{
	while (str1[++i])
	{
		if (str1[i] == 32)
			str1[i] = -32;
		if (str1[i] == 34 || str1[i] == 39)
			j++;
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

char	*quotesremove(char *str)
{
	char	*str1;
	int		i;
	int		j;

	str1 = ft_strdup(str);
	i = -1;
	j = 0;
	return (quotesx2(str1, i, j));
}
