#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
class Entity
{
public:
	float x, y, dx, dy, w, h;
	std::string Name;
	Sprite sprite;
	Entity(sf::Sprite &S, int X, int Y);
	virtual void update(float time) = 0;
	virtual ~Entity();
};
#endif ENTITY_H
