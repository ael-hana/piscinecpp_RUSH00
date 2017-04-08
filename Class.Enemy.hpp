#ifndef ENEMY
# define ENEMY
# include <iostream>
# include "Class.Aplayer.hpp"
# define TOUCH_ENEMY 5;

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
		int				getPosX(void);
		int				getPosY(void);
		int				getAttach(void);
		int				getLife(void);
		std::string		getName(void);
		int				setLife(int);
};
#endif
