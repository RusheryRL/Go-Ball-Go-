#include "wall.h"

#include "raylib.h"

namespace GoBallGo
{
	Wall initWall()
	{
		Wall wall;

		wall.x = static_cast<float>(GetScreenWidth());
		wall.y = static_cast<float>(GetRandomValue(static_cast<int>(PLAYER_WIDTH) * 2, (GetScreenHeight() - static_cast<int>(PLAYER_WIDTH) * 2)));
		wall.h = static_cast<float>(GetScreenHeight());
		wall.w = PLAYER_WIDTH / 1.5f;
		wall.speedX = WALL_SPEED;

		return wall;
	}
	void wallMovement(Wall& wall)
	{
		wall.x -= wall.speedX * GetFrameTime();
	}
	void changeRandomWall(Wall& wall)
	{
		if (wall.x + wall.w <= 0.0f)
		{
			wall.x = static_cast<float>(GetScreenWidth());
			wall.y = static_cast<float>(GetRandomValue(static_cast<int>(PLAYER_WIDTH) * 2, (GetScreenHeight() - static_cast<int>(PLAYER_WIDTH) * 2)));
		}
	}
	void wallPlayerCollision(Wall wall, Player& player)
	{
		if (wall.x + wall.w >= player.x && wall.x <= player.x + player.w &&
			wall.y + wall.h >= player.y && wall.y <= player.y + player.h)
		{
			player.isAlive = false;
		}
	}
}
