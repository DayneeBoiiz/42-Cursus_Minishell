/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:35:14 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/10 20:54:13 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	geti(char *input1)
{
	int	i;

	i = -1;
	while (input1[++i])
	{
		if (input1[i] == '>' || (input1[i] == '>' && input1[i + 1] == '>'))
			break ;
	}
	return (i);
}

int	ft_check_file(char *input, int i)
{
	int	j;

	if (input[i] == '>' && input[i + 1] == '>')
		i++;
	j = ft_strlen(input);
	j--;
	while (j > i)
	{
		if (input[j] != 32)
			return (1);
		j--;
	}
	return (0);
}

void	find_directionb_beta(char *input, t_data *data, int k)
{
	char	*input1;
	char	*tmp;
	int		len;
	int		i;

	input1 = direction_check_beta(input);
	tmp = NULL;
	data->direction = NULL;
	len = ft_strlen(input1);
	i = geti(input1);
	if (input1[i] == '>' && ft_check_file(input, i) == 1)
	{
		if ((input1[i] == '>' && input1[i + 1] == '>'))
		{
			tmp = ft_substr(input, i + 2, len);
			cleaner(tmp, data, k, i);
		}
		else
		{
			tmp = ft_substr(input, i + 1, len);
			cleaner(tmp, data, k, i);
		}
	}
	free(tmp);
	free(input1);
}
