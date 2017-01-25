/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:54:26 by elemarch          #+#    #+#             */
/*   Updated: 2015/08/10 17:54:28 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H

/*
** ==== INCLUDES ============================================================ **
*/

#include <stdlib.h>
#include <stdio.h>

/*
** ==== STRUCTURES ========================================================== **
*/

/*
** ---- s_link -------------------------------------------------------------- **
**	int		| index		| position in the list. 0 is first.					  **
**	void*	| content	| pointer to the value, content of the link			  **
**	t_link*	| next		| pointer to the next link							  **
**	t_link*	| prev		| pointer to the previous link						  **
** -------------------------------------------------------------------------- **
*/

typedef struct		s_link
{
	int				index;
	void			*content;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

/*
** ---- s_link -------------------------------------------------------------- **
**	t_link*	| start		| pointer to the first link							  **
**	int		| sizeof	| number of links in the list						  **
** -------------------------------------------------------------------------- **
*/

typedef struct		s_dlist
{
	t_link			*start;
	int				size;
}					t_dlist;

/*
** ==== FUNCTIONS =========================================================== **
*/

/*
** ---- lst_create.c -------------------------------------------------------- **
** lst_index	| re-index the whole list									  **
** lst_create	| return an empty t_dlist (start = NULL and size = 0)		  **
** -------------------------------------------------------------------------- **
*/

void				lst_index(t_dlist *list);
t_dlist				lst_create();

/*
** ---- lst_add.c ----------------------------------------------------------- **
** after		| add a new link after the link index						  **
** before		| add a new link before the link index						  **
** first		| add a new link at index 0									  **
** end			| add a new link at the end of list							  **
** -------------------------------------------------------------------------- **
*/

void				lst_add_after(int i, t_dlist *list, void *content);
void				lst_add_before(int i, t_dlist *list, void *content);
void				lst_add_first(t_dlist *list, void *content);
void				lst_add_end(t_dlist *list, void *content);

/*
** ---- lst_move.c ---------------------------------------------------------- **
** move			| move link src to dest position							  **
** swap			| swap content a with content b								  **
** start		| move link i to index 0									  **
** end			| move link at the end of list								  **
**  all those functions re-index the list									  **
** -------------------------------------------------------------------------- **
*/

void				lst_move(t_dlist *list, int src, int dest);
void				lst_move_swap(t_dlist *list, int a, int b);
void				lst_move_start(t_dlist *list, int i);
void				lst_move_end(t_dlist *list, int i);

/*
** ---- lst_find.c ---------------------------------------------------------- **
** link			| returns a pointer to the link i							  **
** link			| returns a pointer to the last link of list				  **
** content		| returns a pointer to the content of link i				  **
** -------------------------------------------------------------------------- **
*/

t_link				*lst_find_link(t_dlist *list, int i);
void				*lst_find_content(t_dlist *list, int i);
t_link				*lst_find_end(t_dlist *list);

/*
** ---- lst_clear.c --------------------------------------------------------- **
** list			| clear and free the entire list							  **
** link			| delete a link from the list (does not clear content).		  **
** -------------------------------------------------------------------------- **
*/

void				lst_clear_list(t_dlist *list);
void				lst_clear_link(t_dlist *list, int i);

/*
** ---- lst_error.c --------------------------------------------------------- **
**  0	| list is NULL														  **
**  1	| list is empty (list->start is NULL)								  **
**  2	| link doesn't exist (find_link returns NULL)						  **
**  3	| link couldn't be initialized										  **
**  4	| link content is NULL												  **
**  5	| can not move a link at his own place								  **
** -------------------------------------------------------------------------- **
*/

void				lst_error(int i);

#endif
