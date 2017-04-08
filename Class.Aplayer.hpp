#ifndef APLAYER
# define APLAYER
# include <iostream>
# define TOUCH_ENEMY 5;
# define TOUCH_GAME 0;
# define TOUCH_ATTACK 0;

class Aplayer
{
private:
	Aplayer(std::string, int, int, int, int);
	Aplayer(Aplayer const &);
	Aplayer &operator=(Aplayer const &);

protected:
	int				_life;
	std::string		_name;
	unsigned int	_attack;
	unsigned int	_touch;
	int				_x;
	int				_y;
	int				getPosX(void);
	int				getPosY(void);
	int				getAttach(void);
	int				getLife(void);
	std::string		getName(void);
	int				setLife(int);

public:
	Aplayer(void);
	~Aplayer();
};
#endif
