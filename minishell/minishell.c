/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:57:00 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/07 12:53:15 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	how_to_use(void)
{
	ft_perror("Only 1 arg required\n");
	exit (1);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	t_env	*env;

	if (ac > 1)
		how_to_use();
	rl_catch_signals = 0;
	data = getpath(ac, av);
	env = set_env(data, envp);
	ft_env(data);
	data->exp = set_export(data);
	ft_set_pwd(data);
	ft_shlvl(data);
	pwd(data);
	while (1)
	{
		ft_env(data);
		signalinit();
		to_be_continued(data);
		if (data->inpt && ft_strcmp(data->inpt, "") != 0
			&& ft_space(data->inpt) == 1)
			add_history(data->inpt);
		setall(data->inpt, data);
	}
	return (0);
}
