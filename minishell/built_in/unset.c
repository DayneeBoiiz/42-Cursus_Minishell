/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:35:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:08:12 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset_checker(char *str)
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
		if (str[i] == '=')
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

void	ft_unset(char *input, t_data *data)
{
	char	**split;
	int		i;

	split = ft_split(input, ' ');
	if (split[1] != NULL)
	{
		i = 0;
		while (split[++i])
		{
			if (unset_checker(split[i]) != 0)
			{
				data->msg = split[i];
				ft_strerror(data, unset_checker(split[i]));
				break ;
			}
			delete_lst(data, split[i]);
		}
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	delete_lst2(t_data *data, char *name, int i)
{
	t_export	*xtmp;
	t_export	*delete;

	xtmp = data->exp;
	while (xtmp)
	{
		if (!xtmp->next)
			break ;
		i = get_eq(xtmp->next->data);
		if (ft_strncmplus(xtmp->next->data, name, 11, i - 11) == 0)
		{
			delete = xtmp->next;
			xtmp = expo_delt(xtmp, delete);
		}
		xtmp = xtmp->next;
	}
}

void	delete_lst3(t_data *data, char *name, int i)
{
	t_env		*etmp;
	t_env		*edelete;

	etmp = data->enva;
	while (etmp)
	{
		if (!etmp->next)
			break ;
		i = get_eq(etmp->next->data);
		if (ft_strncmplus(etmp->next->data, name, 0, i) == 0)
		{
			edelete = etmp->next;
			etmp = env_delt(etmp, edelete);
			break ;
		}
		etmp = etmp->next;
	}
}

void	delete_lst(t_data *data, char *name)
{
	int			i;

	i = 0;
	delete_lst2(data, name, i);
	delete_lst3(data, name, i);
	ft_env(data);
}
