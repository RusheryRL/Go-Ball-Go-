#include "player.h"

#include "raylib.h"

#include "game/windowManagment.h"

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
		player.speedX = MAX_PLAYER_SPEED;
		player.speedY = MAX_PLAYER_SPEED;
		player.isAlive = true;
		player.isWinner = false;
		player.currentPlayerLives = MAX_PLAYER_POINTS;
		player.points = 0;

		return player;
	}

	void playerMovment(Player& player)
	{
		if (IsKeyDown(KEY_W))
			player.y -= player.speedY * GetFrameTime();
		if (IsKeyDown(KEY_S))
			player.y += player.speedY * GetFrameTime();
	}
	void playerScreenCollision(Player& player)
	{
		if (player.y <= 0.0f)
			player.y = 0.0f;
		if (player.y + player.h >= GetScreenHeight())
			player.y = GetScreenHeight() - player.h;
	}
}
