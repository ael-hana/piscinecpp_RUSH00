#include "initEnemy.hpp"
#include "Class.Enemy.hpp"
t_node	*insList(t_node *, int = 0);

t_node	*insListEnemy(t_node *ins, int opt = 0)
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

void	list_add_EntitiesEnemy(Aplayer *ins)
{
	t_node *list = new node;
	t_node	*ptr = NULL;

	list->ptr = ins;
	list->next = NULL;
	ptr = insListEnemy(list);
	if (ptr == NULL)
		return;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = list;
}

void	eventLoopEnemy(Ncurse *game, Gamer *g){
	t_node	*ptr;
	t_node	*tmp;
	static int	loop = 0;
	static int	loopins = 3000;
	std::string		tab[] = {"A", "B", "C", "D", "E", "F", "G", "H", "TOTO", "ZIZI",
		"SEGFAULT", "COTON", "ZAZ", "THOR", "PAMPATA"};
	std::string str(tab[rand() % 15]);
	const int			touch = TOUCH_ENEMY;

	++loop;
	if (loop <= 0)
		loop = 1;
	if ((g->getScore() / 100) == 1)
		loopins = 2000;
	if ((g->getScore() / 100) == 3)
		loopins = 1000;
	if ((g->getScore() / 100) >= 5 && loopins > 300)
		loopins -= 1;
	if (loop % loopins == 0)
		list_add_EntitiesEnemy(new Enemy(str, 0, 0, WINDOW_X, rand() % WINDOW_Y));
	ptr = insListEnemy(NULL);
	while (ptr) {
		if (loop % 100 == 0)
		{
			*(ptr->ptr) << *(ptr->ptr);
			if (ptr->ptr->getPosX() == g->getPosX() &&
				ptr->ptr->getPosY() == g->getPosY())
			{
				ptr->ptr->setPosX(0);
				std::cout << " Boloss";
				g->setLife((g->getLife() - touch));
			}
		}
		if (g->getLife() == 0)
			return;
		else if (ptr && ptr->ptr->getPosX() <= 0)
		{
			tmp = ptr->next;
			list_free_EntitiesEnemy(ptr->ptr);
			g->setScore(g->getScore() + touch);
			ptr = tmp;
		}
		else if (ptr)
		{
			game->print(ptr->ptr->getName(), ptr->ptr->getPosY(), ptr->ptr->getPosX());
			ptr = ptr->next;
		}
	}
}

void	list_free_EntitiesEnemy(Aplayer *ins)
{
	t_node	*ptr;
	t_node	*tmp;
	ptr = insListEnemy(NULL);
	if (ptr == NULL)
		return;
	if (ins == ptr->ptr)
	{
		tmp = ptr->next;
		delete ptr->ptr;
		delete ptr;
		insListEnemy(tmp, 1);
		return;
	}
	while (ptr->next)
	{
		if (ins == ptr->next->ptr)
		{
			tmp = ptr->next->next;
			delete ptr->next->ptr;
			delete ptr->next;
			ptr->next = tmp;
			return;
		}
		ptr = ptr->next;
	}
}
