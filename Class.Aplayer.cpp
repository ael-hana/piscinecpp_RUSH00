#include "Class.Aplayer.hpp"

Aplayer::Aplayer(void){
}

Aplayer::Aplayer(std::string str, int life, int attack , int x, int y) {
	this->_name = str;
	this->_life = life;
	this->_attack = attack;
	this->_touch = 0;
	this->_x = x;
	this->_y = y;
}

Aplayer		&Aplayer::operator=(Aplayer const & ins){
	this->_life = ins._life;
	this->_name = ins._name;
	this->_attack = ins._attack;
	this->_touch = ins._touch;
	this->_x = ins._x;
	this->_y = ins._y;
	return (*this);
}

char		const *Aplayer::getName(void){
	return this->_name.c_str();
}

int			Aplayer::getPosX(void){
	return (this->_x);
}

int			Aplayer::getPosY(void){
	return (this->_y);
}

int			Aplayer::getAttach(void){
	return (this->_attack);
}

int			Aplayer::getLife(void){
	return (this->_life);
}

int			Aplayer::setLife(int val){
	this->_life = val;
	if (this->_life < 0)
		this->_life = 0;
	return this->_life;
}

Aplayer	&Aplayer::operator++(void){
	if ((this->_y) < WINDOW_Y)
		++this->_y;
	return (*this);
}

Aplayer	&Aplayer::operator--(void){
	if (this->_y > 0)
		--this->_y;
	return (*this);
}

Aplayer	&Aplayer::operator<<(Aplayer const & ins){
	(void)ins;
	if (this->_x > 0)
		--this->_x;
	return (*this);
}

Aplayer	&Aplayer::operator>>(Aplayer const & ins){
	(void) ins;
	if ((this->_x) < WINDOW_X)
		++this->_x;
	return (*this);
}

Aplayer::~Aplayer(){
}
