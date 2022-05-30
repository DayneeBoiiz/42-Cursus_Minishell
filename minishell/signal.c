/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:51:01 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/13 17:46:44 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler2(int arg)
{
	(void)arg;
	rl_redisplay();
}

void	handler(int arg)
{
	char	*dir;
	char	pwd[100];
	char	**spl;
	int		i;

	(void)arg;
	dir = NULL;
	spl = ft_split(getcwd(pwd, 100), '/');
	t_v.codestatus = 1;
	i = 0;
	while (spl[i + 1])
		i++;
	if (dir)
		free(dir);
	dir = ft_strdup(spl[i]);
	free_pdir(spl);
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	printf("\033[0;32m\033[1m➜ %s\033[0m", dir);
	rl_replace_line("", 0);
	rl_redisplay();
	free(dir);
}

void	signalinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler2);
}
