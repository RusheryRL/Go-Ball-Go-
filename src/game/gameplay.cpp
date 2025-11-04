#include "gameplay.h"

#include "raylib.h"

#include "objects/player.h"
#include "objects/wall.h"
#include "windowManagment.h"

namespace GoBallGo
{
	void GameRun()
	{
		InitWindow(screenWidth, screenHeight, "Go! Ball Go!");
		//Inits
		const int versionTextX = GetScreenWidth() - 65;
		const int versionTextY = GetScreenHeight() - 15;
		Player player = initPlayer();
		Wall wall[MAX_WALLS_IN_SCREEN] = {};

		for (int i = 0; i < MAX_WALLS_IN_SCREEN; i++)
		{
			wall[i] = initWall();
		}

		while (!WindowShouldClose() && player.isAlive)
		{
			//Update
			playerMovment(player);
			playerScreenCollision(player);
			wallUpdate(wall, player);
			//start Draw
			BeginDrawing();
			DrawRectangleLines(static_cast<int>(player.x), static_cast<int>(player.y), static_cast<int>(player.w), static_cast<int>(player.h), RED);
			drawWall(wall);
			DrawText("Ver: 0.1", versionTextX, versionTextY, 15, WHITE);
			ClearBackground(BLACK);

			//end Draw
			EndDrawing();
		}

		//De-Init
		CloseWindow();
	}
}