/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:54:26 by elemarch          #+#    #+#             */
/*   Updated: 2015/08/10 17:54:28 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

static t_link		*lst_add_new(void *content)
{
	t_link		*nlink;

	nlink = (t_link *)malloc(sizeof(t_link));
	if (!nlink)
		return (NULL);
	nlink->content = content;
	nlink->index = 0;
	nlink->next = NULL;
	nlink->prev = NULL;
	return (nlink);
}

void			lst_add_after(int i, t_dlist *list, void *content)
{
	t_link		*nlink;
	t_link		*p;
	t_link		*n;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(p = lst_find_link(list, i)))
		return (lst_error(2));
	if (!(nlink = lst_add_new(content)))
		return (lst_error(3));
	n = lst_find_link(list, i + 1);
	nlink->prev = p;
	nlink->next = n;
	p->next = nlink;
	if (n)
		n->prev = nlink;
	lst_index(list);
	list->size++;
}

void			lst_add_before(int i, t_dlist *list, void *content)
{
	t_link		*nlink;
	t_link		*p;
	t_link		*n;

	if (!list)
		return (lst_error(0));
	if (!list->start)
		return (lst_error(1));
	if (!(n = lst_find_link(list, i)))
		return (lst_error(2));
	if (!(nlink = lst_add_new(content)))
		return (lst_error(3));
	p = lst_find_link(list, i - 1);
	nlink->prev = p;
	nlink->next = n;
	if (p)
		p->next = nlink;
	n->prev = nlink;
	lst_index(list);
	list->size++;
}

void			lst_add_first(t_dlist *list, void *content)
{
	t_link		*nlink;

	if (!list)
		return (lst_error(0));
	if (!(nlink = lst_add_new(content)))
		return (lst_error(3));
	nlink->next = list->start;
	list->start = nlink;
	lst_index(list);
	list->size++;
}

void			lst_add_end(t_dlist *list, void *content)
{
	t_link		*nlink;
	t_link		*last;

	last = lst_find_end(list);
	if (!list)
		return (lst_error(0));
	if (!(nlink = lst_add_new(content)))
		return (lst_error(3));
	nlink->prev = last;
	if (last)
	{
		last->next = nlink;
		nlink->index = last->index + 1;
	}
	else
	{
		list->start = nlink;
		nlink->index = 0;
	}
	list->size++;
}
