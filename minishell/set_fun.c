/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:53:08 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/13 20:41:30 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsingcheck(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '>' || str[i] == '<')
			return (1);
		if (str[i] == '$')
			return (1);
	}
	return (0);
}

int	ft_pipecheck(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			j++;
		if (j % 2 == 0)
		{
			if (str[i] == '|')
				return (1);
		}
	}
	return (0);
}

void	do_echo(char *input, t_data *data)
{
	data->elock = 1;
	ft_echo(input, data);
	data->elock = 0;
}

void	ft_set_fun(char *input, t_data *data)
{
	data->hx = ft_split(input, ' ');
	if (ft_strcmp(data->hx[0], "env") == 0 && data->hx[1] == NULL
		&& data->lline[1] == NULL)
		print_env(data);
	else if (ft_strcmp(data->hx[0], "echo") == 0
		&& ft_pipecheck(input) == 0 && ft_parsingcheck(input) == 0)
		do_echo(input, data);
	else if (ft_strcmp(data->hx[0], "cd") == 0 && data->lline[1] == NULL)
		cdfun(input, data);
	else if (ft_strcmp(data->hx[0], "CD") == 0 && data->lline[1] == NULL)
	{
		freethis(data);
		return ;
	}
	else if (ft_strcmp(data->hx[0], "pwd") == 0 && data->hx[1] == NULL)
		print_pwd(data);
	else if (ft_strcmp(data->hx[0], "export") == 0
		&& ft_strcmp(data->hx[1], "|") != 0 && data->lline[1] == NULL)
		all_export(input, data);
	else if (ft_strcmp(data->hx[0], "unset") == 0 && data->lline[1] == NULL)
		ft_unset(input, data);
	else
		setall2(input, data);
	freethis(data);
}
