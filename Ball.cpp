#include"Ball.h"
#include "Player.h"

Ball::Ball(Sprite &S, int x, int y) :Entity(S, x, y)
{
	sprite = S;
	S.setPosition(x, y);
	dy = 0.25;
	dx = -0.25;
}
void Ball::control() {
	

}


void Ball::update(float time)
{
	checkCoordinatesForMap(y);
	y += dy * time;
	x += dx * time;
	sprite.setPosition(x, y);
	
}
void Ball::checkCoordinatesForMap(int y) {
	if ((y <= 10)|| (y >= 315))
		this->dy *= -1;
}
void Ball::draw(RenderWindow &window)
{
	window.draw(sprite);
}
FloatRect Ball::getRect()
{
	return FloatRect(x, y, w, h);
}
