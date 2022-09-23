#include "entity.h"

Entity::Entity(){  // Entity is a memory type memtype::class namespace
	this->x = 0;
	this->y = 0;
}

Entity::Entity(int x, int y){
	this->x = x;
	this->y = y;
}

Entity::~Entity(){} 

int Entity::a = 2;

int Entity::getX() const { return x; }
int Entity::getY() const { return y; } 
