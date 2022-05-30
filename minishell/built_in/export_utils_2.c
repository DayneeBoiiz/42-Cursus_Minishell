/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:38:16 by sayar             #+#    #+#             */
/*   Updated: 2022/04/14 00:07:45 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_val(t_data *data, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			if (str[i] == '=' && (str[i + 1] == '"' || str[i + 1] == 39))
			{
				i++;
				break ;
			}
			break ;
		}
	}
	j = i + 1;
	while (str[++j])
	{
	}
	get_val2(data, i, j, str);
}

int	expo_checker(char *str)
{
	int		i;

	if (str[0] == '=')
		return (3);
	if (str[0] >= 48 && str[0] <= 57)
		return (4);
	if (!(str[0] == 95 || (str[0] >= 48 && str[0] <= 57)
			|| (str[0] >= 65 && str[0] <= 90)
			|| (str[0] >= 97 && str[0] <= 122)))
		return (4);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && str[i + 1] == '=')
			return (4);
		if (str[i] == '=')
			break ;
		if (!((str[i] >= 48 && str[i] <= 57)
				|| (str[i] >= 65 && str[i] <= 90)
				|| (str[i] >= 97 && str[i] <= 122)))
			return (4);
	}
	return (0);
}

void	echo_free(t_data *data, char *line1, char *line)
{
	t_token	*tmp;

	while (data->start)
	{
		tmp = data->start;
		data->start = data->start->next;
		free(tmp->str);
		free(tmp);
	}
	free(line1);
	if (data->exlock == 1)
		free(line);
}

char	*val_change(char *str, t_data *data)
{
	char	**cmd;
	char	*str1;

	data->exlock = 1;
	str1 = ft_strdup(str);
	cmd = ft_echo1(str1, data);
	str1 = ft_split_join(cmd);
	free_pdir(cmd);
	free(str);
	return (str1);
}
