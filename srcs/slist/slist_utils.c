#include "slist.h"

t_slist_element	*create_slist_element(char const *s, t_slist_element *prev,
									t_slist_element *next)
{
	t_slist_element	*new_slist_element;
	int				i;

	new_slist_element = malloc(sizeof(*new_slist_element));
	if (new_slist_element == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		new_slist_element->s[i] = s[i];
	new_slist_element->s[i] = 0;
	new_slist_element->prev = prev;
	new_slist_element->next = next;
	return (new_slist_element);
}

t_slist_element	*slist_inject(t_slist *slist, char const *s)
{
	t_slist_element	*new_slist_element;

	new_slist_element = create_slist_element(s, slist->tail, slist->head);
	if (new_slist_element == NULL)
	{
		slist_destroy(slist);
		return (NULL);
	}
	if (slist->head == NULL)
	{
		slist->head = new_slist_element;
		slist->tail = new_slist_element;
	}
	slist->tail->next = new_slist_element;
	slist->head->prev = new_slist_element;
	slist->size += 1;
	return (new_slist_element);
}

t_slist	*slist_destroy(t_slist *slist)
{
	t_slist_element	*element;
	t_slist_element	*element_next;

	element = slist->head;
	while (element != slist->tail)
	{
		element_next = element->next;
		free(element);
		element = element_next;
	}
	free(slist->tail);
	slist->head = NULL;
	slist->tail = NULL;
	return (slist);
}
