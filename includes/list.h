#ifndef LIST_H
# define LIST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_list_element
{
	int						value;
	struct s_list_element	*prev;
	struct s_list_element	*next;
}				t_list_element;

typedef struct s_list
{
	t_list_element		*head;
	t_list_element		*tail;
}				t_list;


t_list_element			*create_list_element(int value, t_list_element *prev,
									t_list_element *next);
t_list_element          *list_inject(t_list *list, int value);
size_t                  list_size(t_list *list);
void                    list_destroy(t_list *list);
void                    list_show(t_list list, bool reverse);

void					list_initialize(t_list *list);
t_list_element          *list_push(t_list *list, int data);
int 					list_pop(t_list *list);
t_list_element			*list_unshift(t_list *list, int data);
int         			list_shift(t_list *list);

void					list_swap(t_list * list);
void					list_rotate(t_list *list);
void					list_reverse_rotate(t_list *list);

#endif