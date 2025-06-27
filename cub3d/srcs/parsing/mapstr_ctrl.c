/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstr_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:51:36 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 13:51:40 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	mapstr_addback(t_mapstr **lst, t_mapstr *newstr)
{
	t_mapstr	*og_head;
	t_mapstr	*og_tail;

	og_head = *lst;
	if (!og_head)
		*lst = newstr;
	else if (og_head && !(og_head->prev))
	{
		og_head->next = newstr;
		og_head->prev = newstr;
		newstr->next = og_head;
		newstr->prev = og_head;
	}
	else
	{
		og_tail = og_head->prev;
		og_tail->next = newstr;
		newstr->prev = og_tail;
		newstr->next = og_head;
		og_head->prev = newstr;
	}
}

int	backup_mapstr(char *line, t_mapstr **mapstr)
{
	t_mapstr	*tmp;

	tmp = (t_mapstr *)malloc(sizeof(t_mapstr));
	if (!tmp)
		return (STOP);
	tmp->line = ft_strdup(line);
	if (!(tmp->line))
		return (STOP);
	remove_newline_from_str(&(tmp->line));
	tmp->next = NULL;
	tmp->prev = NULL;
	mapstr_addback(mapstr, tmp);
	return (CONTINUE);
}
