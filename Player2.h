#ifndef PLAYER2_H
#define PLAYER2_H

#include "Entity.h"

class Player2 : public Entity
{
public:
	enum { up, down, stay } state;
	bool key;
	int point;
	Sprite sprite;
	Player2(Sprite &S, int x, int y);
	void update(float time);
	void checkCoordinatesForMap(int y);

};

#endif PLAYER2_H
