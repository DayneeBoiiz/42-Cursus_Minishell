/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:44:07 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/13 20:41:05 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	v1handler(int sig)
{
	(void)sig;
	t_v.dlock = 1;
}

void	heredoc2(t_data *data)
{
	data->stockx = ft_strdup("");
	while (1)
	{
		signal(SIGINT, v1handler);
		if (t_v.dlock == 1)
		{
			free(data->stockx);
			data->stockx = NULL;
			break ;
		}
		data->linex = readline("heredoc> ");
		if (ft_strcmp(data->linex, data->direction2) == 0
			|| data->linex == NULL)
			break ;
		data->sx = ft_strjoin(data->stockx, "^");
		free(data->stockx);
		data->stockx = ft_strjoin(data->sx, data->linex);
		free(data->sx);
		free(data->linex);
	}
}

void	heredoc(t_data *data, int *fd)
{
	int		filefd;
	int		i;

	heredoc2(data);
	data->sline = ft_split(data->stockx, '^');
	filefd = open("hererdoc", O_RDWR | O_CREAT, 0666);
	i = -1;
	while (data->sline[++i])
	{
		write(filefd, data->sline[i], ft_strlen(data->sline[i]));
		write(filefd, "\n", 1);
	}
	dup2(fd[0], 0);
	data->fdq = open("hererdoc", O_RDONLY, 0666);
	dup2(data->fdq, 0);
	unlink("hererdoc");
	free(data->direction2);
	data->direction2 = NULL;
	free_pdir(data->sline);
	free(data->stockx);
}
