#pragma once

#include "player.h"

namespace GoBallGo
{
	struct Wall
	{
		float x;
		float y;
		float w;
		float h;
		float speedX;
	};

	const float DISTANCE_BETWEEN_WALLS = 60.0f;
	const float WALL_SPEED = 200.0f;

	Wall initWall();
	void wallMovement(Wall& wall);
	void changeRandomWall(Wall& wall);
	void wallPlayerCollision(Wall wall, Player& player);
}