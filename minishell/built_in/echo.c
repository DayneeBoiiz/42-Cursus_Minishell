/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:35:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:07:39 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

char	**ft_echo1(char *line, t_data *data)
{
	int		i;
	char	*line1;
	char	**cmd;

	line1 = ft_strdup(line);
	line1 = space_line(line1);
	data->start = get_tokens(line1);
	cmd = cmd_tab(data->start);
	i = 0;
	while (cmd && cmd[i])
	{
		data->echohere = 1;
		cmd[i] = ft_environment(cmd[i], data, 0);
		data->echohere = 0;
		i++;
	}
	echo_free(data, line1, line);
	data->exlock = 0;
	return (cmd);
}

int	ft_chekn(char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] != 'n')
			return (1);
	}
	return (0);
}

int	ft_echo2(char **cmd, int i, int n_option)
{
	if (nb_args(cmd) > 1)
	{
		while (cmd[i] && ft_strncmp(cmd[i], "-n", 2) == 0
			&& ft_chekn(cmd[i]) == 0)
		{
			n_option = 1;
			i++;
		}
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i], 1);
			if (cmd[i + 1] && cmd[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	return (n_option);
}

int	ft_echo(char *line, t_data *data)
{
	char	**cmd;
	int		i;
	int		n_option;

	cmd = ft_echo1(line, data);
	i = 1;
	n_option = 0;
	n_option = ft_echo2(cmd, i, n_option);
	if (n_option == 0)
		write(1, "\n", 1);
	free_pdir(cmd);
	if (data->elock == 0)
		exit(0);
	t_v.codestatus = 0;
	return (0);
}
