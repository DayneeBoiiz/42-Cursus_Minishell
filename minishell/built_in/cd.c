/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:03:23 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:27 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_pwd_export(t_data *data)
{
	t_export	*tmp;
	char		pwd[100];

	tmp = data->exp;
	data->s = NULL;
	data->s2 = NULL;
	data->s3 = NULL;
	getcwd(pwd, 100);
	while (tmp)
	{
		first_if(tmp, data, pwd);
		tmp = tmp->next;
	}
	tmp = data->exp;
	while (tmp)
	{
		secondif(tmp, data, pwd);
		tmp = tmp->next;
	}
}

void	ft_set_pwd(t_data *data)
{
	char	*s;
	char	pwd[100];
	t_env	*tmp;

	tmp = data->enva;
	getcwd(pwd, 100);
	s = NULL;
	while (tmp)
	{
		ft_set_pwd_firstif(tmp, s, pwd);
		tmp = tmp->next;
	}
	tmp = data->enva;
	while (tmp)
	{
		if (boolerv3("PWD", tmp->data) == 1)
		{
			s = ft_strdup("PWD=");
			free(tmp->data);
			tmp->data = ft_strjoin(s, pwd);
			free(s);
		}
		tmp = tmp->next;
	}
	ft_set_pwd_export(data);
}

void	ft_change_pwd_export(t_data *data)
{
	char		pwd[100];
	t_export	*tmp;
	t_export	*tmp2;

	tmp = data->exp;
	tmp2 = NULL;
	data->s = NULL;
	data->s2 = NULL;
	data->s3 = NULL;
	getcwd(pwd, 100);
	while (tmp)
	{
		ft_change_pwd_firstif(tmp, tmp2, data);
		tmp = tmp->next;
	}
	tmp = data->exp;
	while (tmp)
	{
		ft_change_pwd_fsecondif(tmp, data, pwd);
		tmp = tmp->next;
	}
}

void	ft_change_pwd(t_data *data)
{
	char	pwd[100];
	t_env	*tmp;
	t_env	*tmp2;

	tmp = data->enva;
	tmp2 = NULL;
	getcwd(pwd, 100);
	while (tmp)
	{
		if (boolerv3("OLDPWD", tmp->data) == 1)
		{
			ft_change_pwd_first_if(tmp, tmp2, data);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = data->enva;
	ft_change_pwd_hello(tmp, data, pwd);
}

char	*ft_get_env(t_data *data, char *name)
{
	t_env	*tmp;
	char	*path;
	int		i;
	int		len;

	tmp = data->enva;
	path = NULL;
	while (tmp)
	{
		if (boolerv3(name, tmp->data) == 1)
		{
			i = ft_strlen(name) + 1;
			len = ft_strlen(tmp->data);
			path = ft_substr(tmp->data, i, len);
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}
