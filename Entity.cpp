#include "Entity.h"

Entity::Entity(sf::Sprite &S, int X, int Y)
{
	sprite = S;
	x = X;
	y = Y;
	dx = dy = 0;
}
Entity::~Entity() {}
