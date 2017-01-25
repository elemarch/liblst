#include "liblst.h"
#include "libft.h"

#include <stdio.h>

void display_list(t_dlist *list)
{
	t_link *link = list->start;
	while (link)
	{
		printf("link[%d], value: %d\n", link->index, *((int*)link->content));
		link = link->next;
	}
}

int main(){
	t_dlist list = lst_create();
	char contentA = 'A';
	char contentB = 'B';
	char contentC = 'C';
	char contentD = 'D';
	char contentE = 'E';
	char contentF = 'F';
	// add at place 0
	lst_add_first(&list, &contentA);
	// add after link 0
	lst_add_after(0, &list, &contentC);
	//add before link 1
	lst_add_before(1, &list, &contentB);
	// add at the end of the list
	lst_add_end(&list, &contentD);
	lst_add_end(&list, &contentE);
	lst_add_end(&list, &contentF);
	printf("\n\n");
	t_link *test = list.start;
	printf("\033[0;31m-- test: -------------\033[0;0m\n");
	while (test)
	{
		printf("link index: %d\n", test->index);
		printf("link content: %c\n", *(char *)test->content);
		test = test->next;
		printf("\033[0;31m----------------------\033[0;0m\n");
	}
	printf("\033[0;31m   size: %d\033[0;0m\n", list.size);
	// swap links 2 & 1
	lst_move_swap(&list, 2, 0);
	test = list.start;
	printf("\033[0;31m-- test: -------------\033[0;0m\n");
	while (test)
	{
		printf("link index: %d\n", test->index);
		printf("link content: %c\n", *(char *)test->content);
		test = test->next;
		printf("\033[0;31m----------------------\033[0;0m\n");
	}
	printf("\033[0;31m   size: %d\033[0;0m\n", list.size);
	lst_move(&list, 3, 5);
	test = list.start;
	printf("\033[0;31m-- test: -------------\033[0;0m\n");
	while (test)
	{
		printf("link index: %d\n", test->index);
		printf("link content: %c\n", *(char *)test->content);
		test = test->next;
		printf("\033[0;31m----------------------\033[0;0m\n");
	}
	printf("\033[0;31m   size: %d\033[0;0m\n", list.size);
	lst_clear_link(&list, 3);
	test = list.start;
	printf("\033[0;31m-- test: -------------\033[0;0m\n");
	while (test)
	{
		printf("link index: %d\n", test->index);
		printf("link content: %c\n", *(char *)test->content);
		test = test->next;
		printf("\033[0;31m----------------------\033[0;0m\n");
	}
	printf("\033[0;31m   size: %d\033[0;0m\n", list.size);
	lst_clear_list(&list);
	printf("start = %p", list.start->content);
}

