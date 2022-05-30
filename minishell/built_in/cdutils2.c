/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:00:33 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:34 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_change_pwd_first_if(t_env *tmp, t_env *tmp2, t_data *data)
{
	tmp2 = data->enva;
	while (tmp2)
	{
		if (boolerv3("PWD", tmp2->data) == 1)
		{
			free(tmp->data);
			data->s = ft_strdup("OLDPWD=");
			data->s2 = ft_substr(tmp2->data, 4, ft_strlen(tmp2->data));
			tmp->data = ft_strjoin(data->s, data->s2);
			free(data->s);
			free(data->s2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	ft_change_pwd_second_if(t_env *tmp, t_data *data, char *pwd)
{
	free(tmp->data);
	data->s = ft_strdup("PWD=");
	tmp->data = ft_strjoin(data->s, pwd);
	free(data->s);
}

void	cdfun_utils(t_data *data, DIR *dir)
{
	char	pwd[100];

	if (dir)
		closedir(dir);
	if (data->s)
		free(data->s);
	if (getcwd(pwd, 100))
	{
		ft_change_pwd(data);
		ft_change_pwd_export(data);
	}
	if (!(getcwd(pwd, 100)))
		ft_perror("error retrieving current directory\n");
}

void	free_dbl(t_data *data)
{
	int	i;

	i = -1;
	while (data->path[++i])
		free(data->path[i]);
	free(data->path);
}

void	ft_change_pwd_hello(t_env *tmp, t_data *data, char *pwd)
{
	while (tmp)
	{
		if (boolerv3("PWD", tmp->data) == 1)
		{
			ft_change_pwd_second_if(tmp, data, pwd);
			break ;
		}
		tmp = tmp->next;
	}
}
