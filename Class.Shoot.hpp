#ifndef SHOOT
# define SHOOT
# include "Class.Aplayer.hpp"
class Shoot : public Aplayer
{
private:
	Shoot(void);

public:
	Shoot(std::string, int, int, int, int);
	Shoot(Shoot const &);
	Shoot &operator=(Shoot const &);
	virtual ~Shoot();

};
#endif
