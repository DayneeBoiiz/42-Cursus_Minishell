/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:51:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:08:03 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shlvl2(t_data *data)
{
	t_export	*tmp2;

	tmp2 = data->exp;
	while (tmp2)
	{
		if (boolerv4("SHLVL", tmp2->data) == 1)
		{
			data->sx = ft_strdup("declare -x SHLVL=");
			data->sx3 = ft_strjoin3(data->sx, 34);
			data->sx4 = ft_strjoin3(data->sx2, 34);
			free(tmp2->data);
			tmp2->data = ft_strjoin(data->sx3, data->sx4);
			free(data->sx);
			free(data->sx3);
			free(data->sx4);
			free(data->sx2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	ft_shlvl(t_data *data)
{
	t_env		*tmp;
	int			total;

	tmp = data->enva;
	while (tmp)
	{
		if (boolerv3("SHLVL", tmp->data) == 1)
		{
			data->sx = ft_substr(tmp->data, 6, ft_strlen(tmp->data));
			total = ft_atoi(data->sx);
			total++;
			free(data->sx);
			data->sx = ft_strdup("SHLVL=");
			data->sx2 = ft_itoa(total);
			free(tmp->data);
			tmp->data = ft_strjoin(data->sx, data->sx2);
			free(data->sx);
			break ;
		}
		tmp = tmp->next;
	}
	shlvl2(data);
}

void	pwd(t_data *data)
{
	char	*pwd;
	char	pwd2[100];

	pwd = NULL;
	pwd = ft_get_env(data, "PWD");
	if (pwd == NULL)
	{
		getcwd(pwd2, 100);
		if (data->pwd)
			free(data->pwd);
		data->pwd = ft_strdup(pwd2);
	}
	else
	{
		if (data->pwd)
			free(data->pwd);
		data->pwd = ft_strdup(pwd);
	}
	if (pwd)
		free(pwd);
}

void	print_pwd(t_data *data)
{
	printf("%s\n", data->pwd);
}
