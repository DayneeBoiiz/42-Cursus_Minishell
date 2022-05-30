/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:50:04 by sayar             #+#    #+#             */
/*   Updated: 2022/04/13 20:34:33 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line(t_data *data, char *line)
{
	data->xtmp = ft_strdup(line);
	free(line);
	line = ft_strtrimplus(data->xtmp, '"');
	free(data->xtmp);
	data->xtmp = ft_strdup(line);
	free(line);
	line = ft_strtrimplus(data->xtmp, 39);
	free(data->xtmp);
	data->xpath = NULL;
	data->xfpath = NULL;
	return (line);
}

char	*free_path(t_data *data)
{
	int	i;

	i = -1;
	while (data->xpath[++i])
		free(data->xpath[i]);
	free(data->xpath);
	i = -1;
	if (data->xtpath)
	{
		while (data->xtpath[++i])
			free(data->xtpath[i]);
		free(data->xtpath);
	}
	return (data->xfpath);
}

void	find_path2(t_data *data, int l, char *line)
{
	int	i;

	i = 0;
	while (i < l)
	{
		data->xpath[i] = ft_strdup("");
		data->sx = ft_strjoin(data->xpath[i], data->xtpath[i]);
		data->sx1 = ft_strjoin(data->sx, "/");
		free(data->xpath[i]);
		data->xpath[i] = ft_strjoin(data->sx1, line);
		free(data->sx);
		free(data->sx1);
		i++;
	}
	data->xpath[i] = NULL;
	i = 0;
	while (i < l)
	{
		if ((access(data->xpath[i], X_OK)) == 0)
		{
			data->xfpath = ft_strdup(data->xpath[i]);
			break ;
		}
		i++;
	}
}

void	set_here(char **str, t_data *data)
{
	int	i;

	i = -1;
	data->hered = 0;
	while (str[++i])
	{
		if ((ft_tocheckv3(str[i])) == 1)
		data->hered = 1;
	}
}
