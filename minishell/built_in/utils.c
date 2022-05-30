/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:02:06 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:08:14 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	do_magic_utils(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			while (str[i] == '\'')
				i++;
			if (ft_isascii(str[i]) == 1 && (str[i] != '\'' || (str[i] != '\"')))
				return (0);
		}
		if (str[i] == '\"')
		{
			while (str[i] == '\"')
				i++;
			if (ft_isascii(str[i]) == 1 && (str[i] != '\'' || (str[i] != '\"')))
				return (0);
		}
	}
	return (1);
}

void	do_magic(char *str)
{
	int	i;

	if (do_magic_utils(str) == 1)
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] == '\'' || str[i] == '\"')
				str[i] = 127;
		}
	}
}

char	*clean_space(char *str)
{
	char	**plit;
	char	*s1;

	plit = ft_split(str, ' ');
	s1 = ft_split_join(plit);
	free(str);
	free_pdir(plit);
	return (s1);
}
