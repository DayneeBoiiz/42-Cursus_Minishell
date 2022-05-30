/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:41:35 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:07:57 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(t_data *data)
{
	t_export	*tmp;

	tmp = data->exp;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
}

void	free_env(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
}

void	ft_env(t_data *data)
{
	struct s_env	*tmp;
	int				i;

	if (data->env)
		free_env(data);
	tmp = data->enva;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = data->enva;
	data->env = malloc (sizeof(char *) * i + 1);
	i = 0;
	while (tmp)
	{
		data->env[i] = ft_strdup(tmp->data);
		tmp = tmp->next;
		i++;
	}
	data->env[i] = NULL;
}
