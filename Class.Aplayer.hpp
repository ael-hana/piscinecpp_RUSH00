#ifndef APLAYER
# define APLAYER
# include <iostream>
# define TOUCH_ENEMY 5;
# define TOUCH_GAME 0;
# define TOUCH_ATTACK 0;
# define WINDOW_X 79
# define WINDOW_Y 22

class Aplayer
{
private:
	Aplayer(Aplayer const &);
	Aplayer &operator=(Aplayer const &);

protected:
	int				_life;
	std::string		_name;
	unsigned int	_attack;
	unsigned int	_touch;
	int				_x;
	int				_y;

public:
	int				getPosX(void);
	int				getPosY(void);
	int				setPosX(int);
	int				setPosY(int);
	int				getAttach(void);
	int				getLife(void);
	char			const *getName(void);
	int				setLife(int);
	Aplayer			&operator++(void);
	Aplayer			&operator--(void);
	Aplayer	&operator<<(Aplayer const &);
	Aplayer	&operator>>(Aplayer const &);
	virtual			~Aplayer();
	Aplayer(std::string, int, int, int, int);
	Aplayer(void);
};
#endif
