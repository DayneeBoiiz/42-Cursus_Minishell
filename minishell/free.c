/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:44:52 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/10 23:53:23 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all2(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
	free(data->val);
	free(data->name);
	free(data->tocheck);
	free(data->inpt);
	free(data->pwd);
	i = -1;
	if (data->sline)
	{
		while (data->sline[++i])
			free(data->sline);
		free(data->sline);
	}
}

void	free_all(t_data *data)
{
	t_env		*tmp;
	t_env		*head;
	t_export	*tmpx;
	t_export	*headx;

	head = data->enva;
	headx = data->exp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->data);
		free(tmp);
	}
	while (headx)
	{
		tmpx = headx;
		headx = headx->next;
		free(tmpx->data);
		free(tmpx);
	}
	free_all2(data);
}
