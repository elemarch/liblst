/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:43:14 by elemarch          #+#    #+#             */
/*   Updated: 2014/11/09 15:39:13 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_text(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void		lst_error(int i)
{
	if (i == 0)
		print_text("list error: 0 -> list is NULL");
	if (i == 1)
		print_text("list error: 1 -> list is empty");
	if (i == 2)
		print_text("list error: 2 -> link doesn't exist");
	if (i == 3)
		print_text("list error: 3 -> link couldn't be initialized");
	if (i == 4)
		print_text("list error: 4 -> link content is NULL");
	if (i == 5)
		print_text("list error: 5 -> can not move a link at his own place");
}
