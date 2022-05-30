/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:45:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:08:10 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_export	*expo_delt(t_export *xtmp, t_export *delete)
{
	if (xtmp->next->next == NULL)
	{
		free(delete->data);
		free(delete);
		xtmp->next = NULL;
	}
	else
	{
		xtmp->next = xtmp->next->next;
		free(delete->data);
		free(delete);
	}
	return (xtmp);
}

t_env	*env_delt(t_env *etmp, t_env *edelete)
{
	if (etmp->next->next == NULL)
	{
		free(edelete->data);
		free(edelete);
		etmp->next = NULL;
	}
	else
	{
		etmp->next = etmp->next->next;
		free(edelete->data);
		free(edelete);
	}
	return (etmp);
}
