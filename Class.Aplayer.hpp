#ifndef APLAYER
# define APLAYER
# include <iostream>

class Aplayer
{
private:
	Aplayer(std::string);
	Aplayer(Aplayer const &);
	Aplayer &operator=(Aplayer const &);

protected:
	int					_life;
	std::string			_name;
	unsigned int		_attack;
	unsigned int		_touch;
	int					_x;
	int					_y;

public:
	Aplayer(void);
	~Aplayer();
};
#endif
