#include "Class.Enemy.hpp"

Enemy::Enemy(std::string str, int life, int attack , int x, int y) {
	this->_name = str;
	this->_life = life;
	this->_attack = attack;
	this->_touch = TOUCH_ENEMY;
	this->_x = x;
	this->_y = y;
}

Enemy::Enemy(Enemy const &ins){
	*this = ins;
}

Enemy	&Enemy::operator++(void){
	++this->_y;
	return (*this);
}

Enemy	&Enemy::operator--(void){
	--this->_y;
	return (*this);
}

Enemy	&Enemy::operator<<(Enemy const & ins){
	(void)ins;
	--this->_x;
	return (*this);
}

Enemy	&Enemy::operator>>(Enemy const & ins){
	(void) ins;
	++this->_x;
	return (*this);
}

Enemy	&Enemy::operator=(Enemy const & ins){
	this->_name = ins._name;
	this->_life = ins._life;
	this->_x = ins._x;
	this->_y = ins._y;
	this->_attack = ins._attack;
	this->_touch = ins._touch;
	return (*this);
}
