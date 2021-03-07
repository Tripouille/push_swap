#ifndef SLIST_H
# define SLIST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_slist_element
{
	char					s[4];
	struct s_slist_element	*prev;
	struct s_slist_element	*next;
}				t_slist_element;

typedef struct s_slist
{
	t_slist_element		*head;
	t_slist_element		*tail;
}				t_slist;


t_slist_element			*create_slist_element(char const *s, t_slist_element *prev,
									t_slist_element *next);
t_slist_element		 *slist_inject(t_slist *slist, char const *s);
void					slist_destroy(t_slist *slist);

void					slist_initialize(t_slist *slist);
t_slist_element		 *slist_push(t_slist *slist, char const *s);
void 					slist_pop(t_slist *slist);
t_slist_element			*slist_unshift(t_slist *slist, char const *s);
void		 			slist_shift(t_slist *slist);

size_t				  slist_size(t_slist *slist);
void					slist_show(t_slist slist, bool reverse);

#endif