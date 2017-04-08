#include "Ncurse.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "Class.Enemy.hpp"
#include "Class.Gamer.hpp"
#include "Class.Shoot.hpp"
#include "init.hpp"

void	display_limit(Ncurse *game){
	game->clear();
	game->print("*", 0, 0);
	game->print("*", 0, 79);
	game->print("*", 22, 0);
	game->print("*", 22, 79);
}

void print_info(Ncurse *i, int t) { // Player *p
	i->clear();

	i->print("Level:", 0, 0);
	std::stringstream s1;
	s1 << 1; // player->getLevel();
	i->print(s1.str().c_str(), 0, 7);

	i->print("Lives:", 0, 15);
	std::stringstream s2;
	s2 << 1; // player->getLives();
	i->print(s2.str().c_str(), 0, 22);

	i->print("Score:", 0, 30);
	std::stringstream s3;
	s3 << 1; // p->getScore();
	i->print(s3.str().c_str(), 0, 37);

	int tt = time(0) - t;
	i->print("Time:", 0, 45);
	std::stringstream s4;
	s4 << tt;
	i->print(s4.str().c_str(), 0, 51);
}

void		player(Gamer *p, int key){
	if (key == KEY_LEFT)
		*p << *p;
	else if (key == KEY_RIGHT)
		*p >> *p;
	else if (key == KEY_UP)
		--*p;
	else if (key == KEY_DOWN)
		++*p;
	else if (key == 32){
		list_add_Entities(new Shoot("+", 0, 0, p->getPosX() + 1, p->getPosY()));
	}
}

int main(void) {
	time_t start = time(0);
	srand(time(NULL));
	int key;
	Gamer p(">", 10, 0, 10, 10);
	Ncurse title(1, 80, 0, 0);
	Ncurse game(23, 80, 1, 0);
	Ncurse info(1, 80, 24, 0);
	title.print("ft_retro", 0, 36);
	title.refresh();
	while (1) {
		display_limit(&game);
		game.print(p.getName(), p.getPosY(), p.getPosX());
		key = game.waitForInput();
		player(&p, key);
		eventLoop(&game);
		if (key == 27) {
			endwin();
			break;
		}
		print_info(&info, start);
		info.refresh();
		game.refresh();
	}
	return(0);
}
