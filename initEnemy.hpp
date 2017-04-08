#ifndef INITENEMY
# define INITENEMY
# include "init.hpp"
# include "Class.Gamer.hpp"

t_node	*insListEnemy(t_node *, int);
void	list_add_EntitiesEnemy(Aplayer *);
void	eventLoopEnemy(Ncurse *, Gamer *);
void	list_free_EntitiesEnemy(Aplayer *);
#endif
