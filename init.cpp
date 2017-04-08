#include "init.hpp"

t_node	*insList(t_node *ins, int opt = 0)
{
	static t_node *ptr = NULL;

	if (opt == 1)
		ptr = ins;
	else if (ptr == NULL)
	{
		if (ins)
			ptr = ins;
		return NULL;
	}
	return ptr;
}

void	list_add_Entities(Aplayer *ins)
{
	t_node *list = new node;
	t_node	*ptr = NULL;

	list->ptr = ins;
	list->next = NULL;
	ptr = insList(list);
	if (ptr == NULL)
		return;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = list;
}

void	eventLoop(Ncurse *game){
	t_node	*ptr;
	t_node	*tmp;
	static int	loop = 0;

	++loop;
	ptr = insList(NULL);
	while (ptr) {
		if (loop % 100 == 0)
			*(ptr->ptr) >> *(ptr->ptr);
		if (ptr->ptr->getPosY() == WINDOW_Y || ptr->ptr->getPosX() == WINDOW_X)
		{
			tmp = ptr->next;
			list_free_Entities(ptr->ptr);
			ptr = tmp;
		}
		else
		{
			game->print(ptr->ptr->getName(), ptr->ptr->getPosY(), ptr->ptr->getPosX());
			ptr = ptr->next;
		}
	}
}

void	list_free_Entities(Aplayer *ins)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = insList(NULL);
	if (ptr == NULL)
		return;
	if (ins == ptr->ptr)
	{
		tmp = ptr->next;
		delete ptr;
		insList(tmp, 1);
		return;
	}
	while (ptr->next)
	{
		if (ins == ptr->next->ptr)
		{
			tmp = ptr->next->next;
			delete ptr->next;
			ptr->next = tmp;
			return;
		}
		ptr = ptr->next;
	}
}
