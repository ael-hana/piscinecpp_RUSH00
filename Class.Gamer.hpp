#ifndef GAMER
# define GAMER
# include "Class.Aplayer.hpp"
# include <iostream>
class Gamer : public Aplayer
{
private:
	Gamer(void);

public:
	Gamer(std::string, int, int, int, int);
	Gamer(Gamer const &);
	Gamer &operator=(Gamer const &);
	~Gamer();

};
#endif
