/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:27:55 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/10 21:35:53 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	big_dollar_while(t_data *data, char **plit, int i)
{
	data->sx = ft_strjoin3(plit[i], -32);
	data->sx2 = ft_strdup(data->sx1);
	free(data->sx1);
	data->sx1 = ft_strjoin(data->sx2, data->sx);
	free(data->sx);
	free(data->sx2);
}

char	*dollar_line(char *input, t_data *data)
{
	char	*line;
	char	*input2;

	if (ft_strcmp(input, "$?") == 0)
	{
		free(input);
		if (data->k != 0)
			t_v.codestatus = 0;
		input = ft_itoa(t_v.codestatus);
		return (input);
	}
	input2 = ft_substr(input, 1, ft_strlen(input));
	line = ft_get_env(data, input2);
	free(input);
	input = ft_strdup(line);
	free(input2);
	free(line);
	return (input);
}

char	*ft_big_dollar(char *str, t_data *data)
{
	int		i;

	i = -1;
	if (checkmoney(str))
	{
		while (str[++i])
			if (str[i] == '=')
				return (str);
		i = -1;
		data->plit = ft_split(str, -32);
		while (data->plit[++i])
			if (checkmoney(data->plit[i]))
				data->plit[i] = dollar_line(data->plit[i], data);
		i = -1;
		data->sx1 = ft_strdup("");
		while (data->plit[++i])
			big_dollar_while(data, data->plit, i);
		free_pdir(data->plit);
		free(str);
		str = ft_strdup(data->sx1);
		free(data->sx1);
	}
	return (str);
}
