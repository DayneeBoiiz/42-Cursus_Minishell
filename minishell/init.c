/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:21:34 by sayar             #+#    #+#             */
/*   Updated: 2022/04/13 17:44:48 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init2(t_data *data)
{
	data->enva = NULL;
	data->exp = NULL;
	data->fpath = NULL;
	data->msg = NULL;
	data->npwd = NULL;
	data->fecho = NULL;
	data->fpath = NULL;
	data->msg = NULL;
	data->npwd = NULL;
	data->fecho = NULL;
	data->str1 = NULL;
	data->sx = NULL;
	data->sx1 = NULL;
	data->sx2 = NULL;
	data->sx3 = NULL;
	data->sx4 = NULL;
	data->xplit = NULL;
	data->xss = NULL;
	data->nanox = NULL;
	data->fullx = NULL;
	data->strx1 = NULL;
	data->strx = NULL;
	data->rtabx = NULL;
	data->tmpx = NULL;
	data->plinex = NULL;
}

void	ft_init(t_data *data)
{
	data->xxr = NULL;
	data->linex = NULL;
	data->stockx = NULL;
	data->hx = NULL;
	data->trimx = NULL;
	data->nex = NULL;
	data->namex = NULL;
	data->svalx = NULL;
	data->s = NULL;
	data->s2 = NULL;
	data->s3 = NULL;
	data->line1 = NULL;
	data->home = NULL;
	data->dex = NULL;
	data->fpathx = NULL;
	data->tpathx = NULL;
	data->pathx = NULL;
	data->fpathx1 = NULL;
	data->tmpx1 = NULL;
	data->xtpath = NULL;
	data->xpath = NULL;
	data->xfpath = NULL;
	data->xtmp = NULL;
	data->xdouple = NULL;
	ft_init2(data);
}

char	**cmd_tab(t_token *start)
{
	t_token	*token;
	char	**tabs;
	int		i;

	if (!start)
		return (NULL);
	token = start->next;
	i = 2;
	while (token)
	{
		token = token->next;
		i++;
	}
	tabs = malloc(sizeof(char *) * i);
	token = start->next;
	tabs[0] = start->str;
	i = 1;
	while (token)
	{
		tabs[i++] = token->str;
		token = token->next;
	}
	tabs[i] = NULL;
	return (tabs);
}

void	to_be_continued(t_data *data)
{
	getdir(data);
	printf("\033[0;32m\033[1m➜ %s\033[0m", data->dir);
	if (data->inpt)
		free(data->inpt);
	data->inpt = readline("\033[0;32m\033[1m $> \033[0m");
	if (data->inpt)
	{
		if (data->tocheck)
			free(data->tocheck);
		data->tocheck = ft_strdup(data->inpt);
	}
	if (data->inpt == NULL || ft_strcmp(data->inpt, "exit") == 0)
	{
		printf("exit\n");
		free_all(data);
		exit(t_v.codestatus);
	}
}
