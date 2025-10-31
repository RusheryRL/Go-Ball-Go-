#include "player.h"

#include "raylib.h"

#include "game/windowManagment.h"
#include "game/gameplay.h"

using namespace std;
namespace GoBallGo
{
	Player initPlayer()
	{
		Player player;

		player.x = screenWidth / 8;
		player.y = screenHeight / 2;
		player.w = PLAYER_WIDTH;
		player.h = PLAYER_HEIGHT;
		player.speedY = MAX_PLAYER_SPEED;
		player.jump = PLAYER_JUMP_FORCE;
		player.isAlive = true;
		player.currentPlayerLives = MAX_PLAYER_POINTS;
		player.points = 0;

		return player;
	}

	void playerMovment(Player& player)
	{
		if (IsKeyDown(KEY_W))
			player.y -= player.jump * GetFrameTime();
		else
			player.y += Gforce * GetFrameTime();
	}
	void playerScreenCollision(Player& player)
	{
		if (player.y <= 0.0f)
			player.y = 0.0f;
		if (player.y + player.h >= GetScreenHeight())
			player.isAlive = false;
	}
}
