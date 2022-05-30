/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:43:26 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/09 18:01:40 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tocheckv2(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '>' && str[i + 1] == '>')
			return (1);
	return (0);
}

int	ft_tocheckv3(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '<' && str[i + 1] == '<')
			return (1);
	return (0);
}

int	ft_tocheck(t_data *data, char c)
{
	int	i;

	i = -1;
	while (data->tocheck[++i])
		if (data->tocheck[i] == c)
			return (1);
	return (0);
}
