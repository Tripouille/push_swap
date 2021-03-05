#ifndef LIST_H
# define LIST_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_element
{
	void				*data;
	struct s_list_element	*prev;
	struct s_list_element	*next;
}				t_list_element;

typedef struct s_list
{
	t_list_element		*head;
	t_list_element		*tail;
}				t_list;

t_list_element	*list_push(t_list *list, void *data);

#endif