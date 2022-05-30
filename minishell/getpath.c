/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:08:04 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/13 18:02:51 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_errors(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			j++;
	}
	if (j % 2 == 0)
		return (0);
	return (1);
}

int	setall1(char *input, t_data *data)
{
	if (ft_strncmp(input, "exit ", 5) == 0 && data->lline[1] == NULL)
		if (ft_exit(data) == 1)
			return (1);
	if (get_errors(input) == 1)
	{
		ft_perror("wrong input synchronization\n");
		return (1);
	}
	return (0);
}

void	setall2(char *input, t_data *data)
{
	int	i;

	data->direction = NULL;
	data->direction2 = NULL;
	exec(input, data);
	i = 0;
	while (data->pid[i])
	{
		waitpid(data->pid[i], &t_v.wstatus, 0);
		i++;
	}
	if (WTERMSIG(t_v.wstatus) == SIGINT)
	{
		t_v.codestatus = 130;
		write(1, "\n", 1);
	}
	if (WTERMSIG(t_v.wstatus) == SIGQUIT)
	{
		t_v.codestatus = 131;
		write(1, "Quit: 3\n", 8);
	}
	else if (WIFEXITED(t_v.wstatus) && t_v.plock == 0)
		t_v.codestatus = WEXITSTATUS(t_v.wstatus);
	t_v.plock = 0;
	free(data->pid);
}

void	freethis(t_data *data)
{
	int	i;

	i = -1;
	while (data->hx[++i])
		free(data->hx[i]);
	free(data->hx);
}

void	setall(char *input, t_data *data)
{
	char	*str;

	t_v.plock = 0;
	str = ft_strdup(input);
	ft_change(str);
	data->lline = ft_split(str, '|');
	free(str);
	if (setall1(input, data) == 1)
		return ;
	if ((ft_strcmp(input, "")) != 0 && ft_space(input) == 1)
		ft_set_fun(input, data);
	free_pdir(data->lline);
	return ;
}
