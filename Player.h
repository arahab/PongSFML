#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	enum {up,down,stay} state;
	bool key;
	int point;
	Sprite sprite;
	Player(Sprite &S, int x, int y);
	void control();
	void update(float time);
	void checkCoordinatesForMap(int y);
};

#endif PLAYER_H
