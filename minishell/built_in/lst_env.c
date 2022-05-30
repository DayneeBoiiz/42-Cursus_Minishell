/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:43:02 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:08:01 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	all_env(t_data *data)
{
	struct s_env	*tmp;

	tmp = data->enva;
	if (check_eq(data) == 1)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(struct s_env));
		tmp = tmp->next;
		tmp->data = ft_strjoin(data->name, data->val);
		tmp->next = NULL;
	}
	tmp = data->enva;
}
