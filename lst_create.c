/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:43:14 by elemarch          #+#    #+#             */
/*   Updated: 2014/11/09 15:39:13 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void		lst_index(t_dlist *list)
{
	int		i;
	t_link	*cur;

	cur = list->start;
	i = 0;
	while (cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}
t_dlist		lst_create()
{
	t_dlist	list_new;

	list_new.size = 0;
	list_new.start = NULL;
	return (list_new);
}
