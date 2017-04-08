#ifndef INITENEMY
# define INITENEMY
# include "init.hpp"

t_node	*insListEnemy(t_node *, int);
void	list_add_EntitiesEnemy(Aplayer *);
void	eventLoopEnemy(Ncurse *);
void	list_free_EntitiesEnemy(Aplayer *);
#endif
