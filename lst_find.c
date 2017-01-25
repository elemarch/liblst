/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:54:26 by elemarch          #+#    #+#             */
/*   Updated: 2015/08/10 17:54:28 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_link			*lst_find_link(t_dlist *list, int i)
{
	t_link		*cur;

	cur = list->start;
	while (cur && cur->index != i)
		cur = cur->next;
	return (cur);
}

void			*lst_find_content(t_dlist *list, int i)
{
	t_link		*cur;

	cur = lst_find_link(list, i);
	return (cur->content);
}

t_link			*lst_find_end(t_dlist *list)
{
	t_link		*cur;

	cur = list->start;
	while (cur->next)
		cur = cur->next;
	return (cur);
}
