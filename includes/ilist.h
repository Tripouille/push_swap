#ifndef ILIST_H
# define ILIST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_ilist_element
{
	int						value;
	struct s_ilist_element	*prev;
	struct s_ilist_element	*next;
}				t_ilist_element;

typedef struct s_ilist
{
	t_ilist_element		*head;
	t_ilist_element		*tail;
}				t_ilist;


t_ilist_element			*create_ilist_element(int value, t_ilist_element *prev,
									t_ilist_element *next);
t_ilist_element          *ilist_inject(t_ilist *ilist, int value);
void                    ilist_destroy(t_ilist *ilist);

void					ilist_initialize(t_ilist *ilist);
t_ilist_element          *ilist_push(t_ilist *ilist, int data);
int 					ilist_pop(t_ilist *ilist);
t_ilist_element			*ilist_unshift(t_ilist *ilist, int data);
int         			ilist_shift(t_ilist *ilist);

void					ilist_swap(t_ilist * ilist);
void					ilist_rotate(t_ilist *ilist);
void					ilist_reverse_rotate(t_ilist *ilist);

bool					ilist_is_sort(t_ilist *ilist, bool descending);
bool					ilist_contain(t_ilist *ilist, int needle);
size_t                  ilist_size(t_ilist *ilist);
void                    ilist_show(t_ilist ilist, bool reverse);
#endif