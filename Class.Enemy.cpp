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
	return (*this);
}

std::string		Enemy::getName(void){
	return this->_name;
}

int			Enemy::getPosX(void){
	return (this->_x);
}

int			Enemy::getPosY(void){
	return (this->_y);
}

int			Enemy::getAttach(void){
	return (this->_attack);
}

int			Enemy::getLife(void){
	return (this->_life);
}

int			Enemy::setLife(int val){
	this->_life = val;
	if (this->_life < 0)
		this->_life = 0;
	return this->_life;
}
