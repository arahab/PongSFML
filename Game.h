#include <SFML/Graphics.hpp>
#include"Player.h"
#include "Player2.h"
#include"Ball.h"
#include <list>
#include<iostream>
#include <sstream>
#include<time.h>
static int points1 = 0, points2 = 0;
using namespace sf;
void RunGame(RenderWindow &window);