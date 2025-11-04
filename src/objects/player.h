#pragma once

#include "raylib.h" 

namespace GoBallGo
{
	struct Player
	{
		float x;
		float y;
		float h;
		float w;
		float speedY;
		float jump;

		bool isAlive;
		bool isWinner;

		int currentPlayerLives;
		int points;
	};

	const int MAX_PLAYER_POINTS = 5;

	const float PLAYER_WIDTH = 45.0f;
	const float PLAYER_HEIGHT = 45.0f;
	const float MAX_PLAYER_SPEED = 150.0f;
	const float PLAYER_JUMP_FORCE = 250.0f;
	const float MAX_PLAYER_JUMP_FORCE = 150000.0f;

	Player initPlayer();
	void playerMovment(Player& player);
	void playerScreenCollision(Player& player);
	void playerClamp(Player& player);
}