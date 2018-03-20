#include "Player2.h"

Player2::Player2(Sprite &S, int x, int y) :Entity(S, x, y)
{
	key = false;
	state = stay;
	sprite = S;
	S.setPosition(x, y);
	dy = 0;
	point = 0;
}


void Player2::update(float time)
{
	checkCoordinatesForMap(y);
	y += dy * time;
	sprite.setPosition(x, y);
}
void Player2::checkCoordinatesForMap(int y) {
	if (y <= 10)
		this->y = 11;
	if (y >= 250)
		this->y = 250;
}
