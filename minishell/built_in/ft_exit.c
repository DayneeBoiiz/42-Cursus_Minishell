/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:33:41 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:07:59 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit1(t_data *data, char **plit)
{
	int	code;

	if (plit[1] && plit[2] == NULL)
	{
		if (plit[1][0] == '\"')
			plit[1] = ft_strtrim(plit[1], "\"");
		code = ft_atoi(plit[1]);
		free_pdir(plit);
		free_all(data);
		exit(code);
	}
	ft_perror("exit: too many arguments\n");
	return (1);
}

int	ft_exit(t_data *data)
{
	char	**plit;
	int		i;

	plit = NULL;
	i = -1;
	plit = ft_split(data->inpt, ' ');
	while (plit[1][++i])
	{
		if (ft_isalpha(plit[1][i]) == 1)
		{
			ft_perror("exit\nnumeric argument required\n");
			exit(255);
		}
	}
	return (ft_exit1(data, plit));
}
