#ifndef ENEMY
# define ENEMY
# include <iostream>
# include "Class.Aplayer.hpp"

class Enemy : public Aplayer
{
	private:
		Enemy(void);

	public:
		Enemy(Enemy const &);
		Enemy &operator=(Enemy const &);
		~Enemy(void);
		Enemy(std::string, int, int, int, int);
		Enemy &operator++(void);
		Enemy &operator--(void);
		Enemy &operator<<(Enemy const &);
		Enemy &operator>>(Enemy const &);
};
#endif
