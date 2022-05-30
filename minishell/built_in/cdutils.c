/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:07:49 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:32 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	first_if(t_export *tmp, t_data *data, char *pwd)
{
	if (boolerv4("OLDPWD", tmp->data) == 1)
	{
		data->s = ft_strdup("declare -x ");
		data->s2 = ft_strdup("OLDPWD=");
		data->s3 = ft_strjoin(data->s, data->s2);
		free(data->s);
		free(data->s2);
		data->s = ft_strjoin3(data->s3, 34);
		data->s2 = ft_strjoin3(pwd, 34);
		free(tmp->data);
		tmp->data = ft_strjoin(data->s, data->s2);
		free(data->s);
		free(data->s2);
		free(data->s3);
	}
}

void	secondif(t_export *tmp, t_data *data, char *pwd)
{
	if (boolerv4("PWD", tmp->data) == 1)
	{
		data->s = ft_strdup("declare -x ");
		data->s2 = ft_strdup("PWD=");
		data->s3 = ft_strjoin(data->s, data->s2);
		free(data->s);
		free(data->s2);
		data->s = ft_strjoin3(data->s3, 34);
		data->s2 = ft_strjoin3(pwd, 34);
		free(tmp->data);
		tmp->data = ft_strjoin(data->s, data->s2);
		free(data->s);
		free(data->s2);
		free(data->s3);
	}
}

void	ft_set_pwd_firstif(t_env *tmp, char *s, char *pwd)
{
	if (boolerv3("OLDPWD", tmp->data) == 1)
	{
		s = ft_strdup("OLDPWD=");
		free(tmp->data);
		tmp->data = ft_strjoin(s, pwd);
		free(s);
	}
}

void	ft_change_pwd_firstif(t_export *tmp, t_export *tmp2, t_data *data)
{
	if (boolerv4("OLDPWD", tmp->data) == 1)
	{
		tmp2 = data->exp;
		while (tmp2)
		{
			if (boolerv4("PWD", tmp2->data) == 1)
			{
				data->s = ft_strdup("declare -x ");
				data->s2 = ft_strdup("OLDPWD=");
				data->s3 = ft_strjoin(data->s, data->s2);
				free(data->s);
				free(data->s2);
				data->s = ft_substr(tmp2->data, 15, ft_strlen(tmp2->data));
				free(tmp->data);
				tmp->data = ft_strjoin(data->s3, data->s);
				free(data->s);
				free(data->s3);
				break ;
			}
			tmp2 = tmp2->next;
		}
	}
}

void	ft_change_pwd_fsecondif(t_export *tmp, t_data *data, char *pwd)
{
	if (boolerv4("PWD", tmp->data) == 1)
	{
		data->s = ft_strdup("declare -x ");
		data->s2 = ft_strdup("PWD=");
		data->s3 = ft_strjoin(data->s, data->s2);
		free(data->s);
		free(data->s2);
		data->s = ft_strjoin3(data->s3, 34);
		data->s2 = ft_strjoin3(pwd, 34);
		free(tmp->data);
		tmp->data = ft_strjoin(data->s, data->s2);
		free(data->s);
		free(data->s2);
		free(data->s3);
	}
}
