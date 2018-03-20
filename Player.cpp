#include "Player.h"

Player::Player( Sprite &S, int x, int y) :Entity(S, x, y)
{
	key = false;
	state = stay;
	sprite = S;
	S.setPosition(x, y);
	dy = 0;
	point = 0;
}
void Player::control() {
	if (Keyboard::isKeyPressed) {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			state = up; key = true;

		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			state = down; key = true;
		}
		if (key==false)
			state = stay;
	}
	key = false;
	
}


void Player::update(float time)
{
	control();
	switch (state)
	{
	case up:
		dy = -0.22;
		break;
	case down:
		dy = 0.22;
		break;
	case stay:
		dy = 0;
		break;
	}
	checkCoordinatesForMap(y);
	y += dy * time;
	sprite.setPosition(x, y);
}
void Player::checkCoordinatesForMap(int y) {
	if (y<=10)
		this->y = 11 ;
	if (y >= 250)
		this->y = 250;
}