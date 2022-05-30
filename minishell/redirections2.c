/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:35:14 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/10 20:54:18 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	geti2(char *input1)
{
	int	i;

	i = -1;
	while (input1[++i])
	{
		if (input1[i] == '<' || (input1[i] == '<' && input1[i + 1] == '<'))
			break ;
	}
	return (i);
}

char	*direction_check_beta2(char *str)
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
			if (str1[i] == '<')
				str1[i] = (char)(-str1[i]);
		}
	}
	return (str1);
}

void	ccleaner3(t_data *data, int j)
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

void	cleaner2(char *tmp, t_data *data, int k, int i)
{
	int	j;

	data->xss = quotesremove(tmp);
	data->xplit = ft_split(data->xss, -32);
	free(data->xss);
	j = 0;
	if (data->xplit[0][0] == 34)
		data->direction2 = ft_strtrimplus(data->xplit[0], 34);
	else if (data->xplit[0][0] == 39)
		data->direction2 = ft_strtrimplus(data->xplit[0], 39);
	else
		data->direction2 = ft_strdup(data->xplit[0]);
	data->sx1 = ft_substr(data->pline[k], 0, i);
	ccleaner3(data, j);
	free(data->pline[k]);
	data->pline[k] = ft_strdup(data->sx1);
	free(data->sx1);
	j = -1;
	while (data->xplit[++j])
		free(data->xplit[j]);
	free(data->xplit);
}

void	find_directionb_beta2(char *input, t_data *data, int k)
{
	char	*input1;
	char	*tmp;
	int		len;
	int		i;

	input1 = direction_check_beta2(input);
	tmp = NULL;
	data->direction = NULL;
	len = ft_strlen(input1);
	i = geti2(input1);
	if (input1[i] == '<')
	{
		if ((input1[i] == '<' && input1[i + 1] == '<'))
		{
			tmp = ft_substr(input, i + 2, len);
			cleaner2(tmp, data, k, i);
		}
		else
		{
			tmp = ft_substr(input, i + 1, len);
			cleaner2(tmp, data, k, i);
		}
	}
	free(tmp);
	free(input1);
}
