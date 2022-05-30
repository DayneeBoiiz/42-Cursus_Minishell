/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:53:46 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/13 22:18:20 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parent(t_data *data, int *fd)
{
	int	i;

	signal(SIGINT, SIG_IGN);
	close(fd[1]);
	if (data->fdd)
		close(data->fdd);
	data->fdd = fd[0];
	if (data->xxfpath)
		free(data->xxfpath);
	if (data->fecho)
		free(data->fecho);
	i = -1;
	while (data->line[++i])
		free(data->line[i]);
	free(data->line);
}

void	free_execve(t_data *data)
{
	int	i;

	if (data->direction)
		free(data->direction);
	if (data->direction2)
		free(data->direction2);
	i = -1;
	while (data->pline[++i])
		free(data->pline[i]);
	free(data->pline);
	i = -1;
	while (data->xdouple[++i])
		free(data->xdouple[i]);
	free(data->xdouple);
}

int	ft_fork(t_data *data, int k, int *fd)
{
	data->pid[k] = fork();
	if (data->pid[k] == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (data->pid[k] == 0)
	{
		ft_if_heredoc(data, k, fd);
		ft_get_direction2(data, k, fd);
		ft_get_direction(data, k);
		close(fd[0]);
		ft_execve(data);
	}
	else
	{
		if (data->hered == 1)
			wait(&t_v.codestatus);
		ft_parent(data, fd);
		k++;
	}
	return (k);
}
