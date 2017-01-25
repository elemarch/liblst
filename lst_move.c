/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:54:26 by elemarch          #+#    #+#             */
/*   Updated: 2015/08/10 17:54:28 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void				lst_move_start(t_dlist *list, int i)
{
	t_link			*link;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(link = lst_find_link(list, i)))
		return (lst_error(2));
	if (!i)
		return (lst_error(5));
	link->prev->next = link->next;
	if (link->next)
		link->next->prev = link->prev;
	link->next = list->start;
	link->prev = NULL;
	list->start = link;
	link->next->prev = link;
	lst_index(list);
}

void				lst_move_end(t_dlist *list, int i)
{
	t_link			*link;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(link = lst_find_link(list, i)))
		return (lst_error(2));
	if (i == list->size - 1)
		return (lst_error(5));
	if (link->prev)
		link->prev->next = link->next;
	link->next->prev = link->prev;
	link->prev = lst_find_end(list);
	link->prev->next = link;
	link->next = NULL;
	lst_index(list);
}

void				lst_move(t_dlist *list, int src, int dest)
{
	t_link			*ls;
	t_link			*ld;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(ls = lst_find_link(list, src)))
		return (lst_error(2));
	if (src == dest)
		return (lst_error(5));
	if (dest == 0)
		return (lst_move_start(list, src));
	if (dest == list->size - 1)
		return (lst_move_end(list, src));
	ls->next->prev = ls->prev;
	ls->prev->next = ls->next;
	lst_index(list);
	if (!(ld = lst_find_link(list, dest - 1)))
		return (lst_error(2));
	ls->next = ld->next;
	ls->prev = ld;
	ld->next = ls;
	ls->next->prev = ls;
	lst_index(list);
}

void				lst_move_swap(t_dlist *list, int a, int b)
{
	t_link			*lka;
	t_link			*lkb;
	void			*buf;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(lka = lst_find_link(list, a)) || !(lkb = lst_find_link(list, b)))
		return (lst_error(2));
	if (!lka->content || !lkb->content)
		return (lst_error(4));
	buf = lka->content;
	lka->content = lkb->content;
	lkb->content = buf;
}

