/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:07:50 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:08:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

struct s_env	*set_env(t_data *data, char **envp)
{
	struct s_env	*head;
	struct s_env	*tail;
	int				i;

	head = malloc(sizeof(struct s_env));
	head->data = ft_strdup(envp[0]);
	tail = head;
	i = 0;
	while (envp[++i])
	{
		tail->next = malloc(sizeof(struct s_env));
		tail = tail->next;
		tail->data = ft_strdup(envp[i]);
		tail->next = NULL;
	}
	data->enva = head;
	return (head);
}

void	set_export2(t_data *data, int len, t_export *tail)
{
	int	i;

	i = 0;
	while (data->env[++i])
	{
		len = ft_strlen(data->env[i]) + 1;
		tail->next = malloc(sizeof(struct s_export));
		tail = tail->next;
		data->sx1 = ft_substr2(data->env[i], 0, get_eq(data->env[i]) + 1);
		data->sx2 = ft_substr2(data->env[i], get_eq(data->env[i]) + 1, len);
		data->fullx = ft_strjoin(data->sx1, data->sx2);
		free(data->sx1);
		free(data->sx2);
		data->nanox = ft_strdup(data->fullx);
		tail->data = ft_strjoin("declare -x ", data->nanox);
		free(data->nanox);
		free(data->fullx);
		tail->next = NULL;
	}
}

struct s_export	*set_export(t_data *data)
{
	struct s_export	*head;
	struct s_export	*tail;
	int				len;

	len = ft_strlen(data->env[0]) + 1;
	head = malloc(sizeof(struct s_export));
	data->sx1 = ft_substr2(data->env[0], 0, get_eq(data->env[0]) + 1);
	data->sx2 = ft_substr2(data->env[0], get_eq(data->env[0]) + 1, len);
	data->fullx = ft_strjoin(data->sx1, data->sx2);
	free(data->sx1);
	free(data->sx2);
	data->nanox = ft_strdup(data->fullx);
	head->data = ft_strjoin("declare -x ", data->nanox);
	free(data->nanox);
	free(data->fullx);
	tail = head;
	set_export2(data, len, tail);
	return (head);
}
