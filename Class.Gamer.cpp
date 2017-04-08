#include "Class.Gamer.hpp"

Gamer::Gamer(std::string str, int life, int attack, int x, int y){
	this->_name = str;
	this->_life = life;
	this->_attack = attack;
	this->_touch = TOUCH_GAME;
	this->_x = x;
	this->_y = y;
}

Gamer &Gamer::operator=(Gamer const & ins){
	this->_name = ins._name;
	this->_life = ins._life;
	this->_x = ins._x;
	this->_y = ins._y;
	this->_attack = ins._attack;
	this->_touch = ins._touch;
	return (*this);
}

Gamer::Gamer(Gamer const & ins){
	*this = ins;
}
