#include "Class.Aplayer.hpp"

Aplayer		&Aplayer::operator=(Aplayer const & ins){
	this->_life = ins._life;
	this->_name = ins._name;
	this->_attack = ins._attack;
	this->_touch = ins._touch;
	return (*this);
}
