/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:54:26 by elemarch          #+#    #+#             */
/*   Updated: 2015/08/10 17:54:28 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void				lst_clear_list(t_dlist *list)
{
	t_link			*link;
	t_link			*next;

	if (!list)
		return (lst_error(0));
	if (!(link = list->start))
		return (lst_error(1));
	while (link)
	{
		next = link->next;
		free(link);
		link = next;
	}
}

void				lst_clear_link(t_dlist *list, int i)
{
	t_link			*link;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(link = lst_find_link(list, i)))
		return (lst_error(2));
	if (link->prev)
		link->prev->next = link->next;
	if (link->next)
	{
		if (i == 0)
			list->start = link->next;
		link->next->prev = link->prev;
	}
	free(link);
	link = NULL;
	lst_index(list);
}

