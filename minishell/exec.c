/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:06:11 by sayar             #+#    #+#             */
/*   Updated: 2022/04/13 20:34:08 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipecheck(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '|')
			j++;
		i++;
	}
	return (j);
}

t_data	*getpath(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	(void)ac;
	(void)av;
	data->inpt = NULL;
	data->path = NULL;
	data->line = NULL;
	data->pline = NULL;
	data->inpt = NULL;
	data->check = NULL;
	data->pdir = NULL;
	data->dir = NULL;
	data->pwd = NULL;
	data->direction = NULL;
	data->direction2 = NULL;
	data->tocheck = NULL;
	data->sline = NULL;
	data->env = NULL;
	data->val = NULL;
	data->name = NULL;
	data->xxfpath = NULL;
	ft_init(data);
	return (data);
}

int	path_count(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ':')
			j++;
	}
	return (j);
}

char	*findpath(t_data *data, char *line)
{
	int		i;
	int		l;

	line = get_line(data, line);
	if ((access(line, X_OK)) == 0)
	{
		data->xfpath = ft_strdup(line);
		return (data->xfpath);
	}
	if (ft_isalnum(line[0]) == 0)
		return (NULL);
	i = -1;
	while (data->env[++i])
		if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
			break ;
	if (data->env[i] == NULL)
	{
		data->xfpath = NULL;
		return (data->xfpath);
	}
	data->xtpath = ft_split(data->env[i], ':');
	l = path_count(data->env[i]) + 1;
	data->xpath = malloc(sizeof(char *) * l + 1);
	find_path2(data, l, line);
	return (free_path(data));
}

void	exec(char *input, t_data *data)
{
	int		fd[2];
	int		k;

	data->fdd = 0;
	data->pid = malloc(sizeof(pid_t) * pipecheck(input) + 1);
	if (ft_get_error(input) == 1)
	{
		ft_perror("syntax error near unexpected token\n");
		return ;
	}
	ft_change(data->inpt);
	data->pline = ft_split(data->inpt, '|');
	data->xdouple = ft_split(data->inpt, '|');
	set_here(data->xdouple, data);
	ft_change_parsing(data->xdouple);
	k = 0;
	while (data->pline[k] != NULL)
	{
		ft_if_direction(data, k);
		pipe(fd);
		k = ft_fork(data, k, fd);
	}
	free_execve(data);
}
