/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:28:14 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/13 23:12:44 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*direction_check_beta(char *str)
{
	char	*str1;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str1 = ft_strdup(str);
	while (str1[++i])
	{
		if (str1[i] == 34 || str1[i] == 39)
			j++;
		if (j % 2 != 0)
		{
			if (str1[i] == '>')
				str1[i] = (char)(-str1[i]);
		}
	}
	return (str1);
}

char	*qoutes2(char *str1, int j, int i)
{
	while (str1[++i])
	{
		if (str1[i] == 32)
			str1[i] = (char)(-str1[i]);
		if (str1[i] == 34 || str1[i] == 39)
		{
			j++;
			str1[i] = -32;
		}
		if (j % 2 != 0 && j != 0)
		{
			while (str1[++i])
			{
				if (str1[i] == 34 || str1[i] == 39)
				{
					str1[i] = -32;
					j++;
					break ;
				}
			}
		}
	}
	return (str1);
}

char	*quotesremove_mini(char *str)
{
	char	*str1;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	str1 = ft_strdup(str);
	free(str);
	i = -1;
	j = 0;
	return (qoutes2(str1, j, i));
}

void	ccleaner2(t_data *data, int j)
{
	while (data->xplit[++j])
	{
		data->sx2 = ft_strjoin(" ", data->xplit[j]);
		data->sx3 = ft_strjoin(data->sx1, data->sx2);
		free(data->sx1);
		data->sx1 = ft_strdup(data->sx3);
		free(data->sx3);
		free(data->sx2);
	}
}

void	cleaner(char *tmp, t_data *data, int k, int i)
{
	int	j;

	data->xss = quotesremove(tmp);
	data->xplit = ft_split(data->xss, -32);
	free(data->xss);
	j = 0;
	if (data->xplit[0][0] == 34)
		data->direction = ft_strtrimplus(data->xplit[0], 34);
	else if (data->xplit[0][0] == 39)
		data->direction = ft_strtrimplus(data->xplit[0], 39);
	else
		data->direction = ft_strdup(data->xplit[0]);
	data->sx1 = ft_substr(data->pline[k], 0, i);
	ccleaner2(data, j);
	free(data->pline[k]);
	data->pline[k] = ft_strdup(data->sx1);
	free(data->sx1);
	j = -1;
	while (data->xplit[++j])
		free(data->xplit[j]);
	free(data->xplit);
}
