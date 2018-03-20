#ifndef BALL_H
#define BALL_H

#include "Entity.h"

class Ball : public Entity
{
public:
	Sprite sprite;
	Ball(Sprite &S, int x, int y);
	void control();
	void update(float time);
	void checkCoordinatesForMap(int y);
	void draw(RenderWindow &window);
	FloatRect getRect();
};

#endif BALL_H