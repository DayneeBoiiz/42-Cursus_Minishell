/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:24:37 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:01:34 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_if_direction(t_data *data, int k)
{
	data->k = k;
	if (check_redi(data->pline[k]) == 1)
		find_directionb_beta(data->pline[k], data, k);
	if (check_redi(data->pline[k]) == 2)
		find_directionb_beta2(data->pline[k], data, k);
	data->fecho = ft_strdup(data->pline[k]);
	data->pline[k] = quotesremove_mini(data->pline[k]);
	if (ft_strstr(data->pline[k], "echo") != 1)
		data->pline[k] = ft_big_dollar(data->pline[k], data);
	data->line = ft_split(data->pline[k], -32);
	data->xxfpath = NULL;
	if (!(data->line[0] == 0))
		data->xxfpath = findpath(data, data->line[0]);
	if (data->xxfpath == NULL && data->pline[k + 1] == NULL)
	{
		t_v.plock = 1;
		t_v.codestatus = 127;
	}
}

void	ft_get_direction2(t_data *data, int k, int *fd)
{
	if (ft_strchr(data->xdouple[k], '<') != 0 && data->direction2)
	{
		if (!(ft_tocheckv3(data->xdouple[k]) == 1))
		{
			dup2(fd[0], 0);
			close(fd[0]);
			data->fdq = open(data->direction2, O_RDONLY, 0666);
			if (data->fdq < 0)
			{
				ft_strerror(data, 1);
				exit(1);
			}
			dup2(data->fdq, 0);
			close(data->fdq);
			free(data->direction2);
			data->direction2 = NULL;
		}
	}
}

void	ft_get_direction(t_data *data, int k)
{
	if (ft_strchr(data->xdouple[k], '>') != 0 && data->direction)
	{
		if ((ft_tocheckv2(data->xdouple[k])) == 1)
		{
			data->xfilefd = open(data->direction, O_RDWR
					| O_CREAT | O_APPEND, 0666);
			if (data->xfilefd < 0)
				ft_strerror(data, 1);
		}
		else
			data->xfilefd = open(data->direction, O_RDWR
					| O_CREAT | O_TRUNC, 0666);
		if (data->xfilefd < 0)
			ft_strerror(data, 1);
		dup2(data->xfilefd, 1);
		close(data->xfilefd);
		free(data->direction);
		data->direction = NULL;
	}
}

void	ft_if_heredoc(t_data *data, int k, int *fd)
{
	if (ft_strchr(data->xdouple[k], '<') != 0 && data->direction2)
		if ((ft_tocheckv3(data->xdouple[k])) == 1)
			heredoc(data, fd);
	if (!(data->xdouple[k + 1] == NULL
			&& check_doc(data->xdouple[k]) == 1))
	{
		dup2(data->fdd, 0);
		if (data->pline[k + 1] != NULL)
		{
			dup2(fd[1], 1);
			close(fd[1]);
		}
	}
}

void	ft_execve(t_data *data)
{
	if ((ft_strcmp(data->line[0], "echo") == 0))
		ft_echo(data->fecho, data);
	else
	{
		if ((ft_strcmp(data->line[0], "env") == 0))
		{
			print_env(data);
			exit(0);
		}
		else if ((ft_strcmp(data->line[0], "export") == 0))
		{
			print_export(data);
			exit(0);
		}
		else if ((ft_strcmp(data->line[0], "pwd") == 0))
		{
			print_pwd(data);
			exit(0);
		}
		if (execve(data->xxfpath, data->line, data->env) < 0)
			if (data->line[0])
				ft_handle_error(data);
		exit(1);
	}
}
