#include "player.h"

#include <iostream>
#include <cmath>

#include "raylib.h"

#include "game/windowManagment.h"

using namespace std;
namespace GoBallGo
{
	Player initPlayer()
	{
		Player player;

		player.x = screenWidth / 2;
		player.y = screenHeight / 2;
		player.w = PLAYER_WIDTH;
		player.h = PLAYER_HEIGHT;
		player.speedX = 0.0f;
		player.speedY = 0.0f;
		player.isAlive = true;
		player.isWinner = false;
		player.currentPlayerLives = MAX_PLAYER_POINTS;
		player.points = 0;

		return player;
	}

	void playerMovment(Player& player)
	{
	}
	void playerScreenCollision(Player& player)
	{
	}
}
