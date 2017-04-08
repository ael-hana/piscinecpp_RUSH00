#include "Class.Aplayer.hpp"

Aplayer		&Aplayer::operator=(Aplayer const & ins){
	this->_life = ins._life;
	this->_name = ins._name;
	this->_attack = ins._attack;
	this->_touch = ins._touch;
	this->_x = ins._x;
	this->_y = ins._y;
	return (*this);
}

std::string		Aplayer::getName(void){
	return this->_name;
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
