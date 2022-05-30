/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:06:58 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:36 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	home_not_found(t_data *data)
{
	data->home = ft_get_env(data, "HOME");
	if (!(data->home))
		write(1, "HOME not set\n", 13);
	data->line1 = ft_strjoin("/", data->home);
	free(data->home);
}

void	cdfun(char *input, t_data *data)
{
	DIR		*dir;

	dir = NULL;
	data->line1 = NULL;
	data->home = NULL;
	data->path = ft_split(input, ' ');
	data->s = ft_strjoin("./", data->path[1]);
	if (data->path[1] != NULL)
		dir = opendir(data->s);
	if (data->path[1] == NULL)
		home_not_found(data);
	else if (dir != NULL)
		data->line1 = ft_strjoin("./", data->path[1]);
	else
		data->line1 = ft_strjoin("/", data->path[1]);
	if (chdir(data->line1) < 0 && data->path[1] != NULL)
	{
		t_v.codestatus = 1;
		ft_perror("Directory not found\n");
	}
	free_dbl(data);
	cdfun_utils(data, dir);
	if (ft_strcmp(data->line1, "./.") != 0)
		pwd(data);
	free(data->line1);
}
