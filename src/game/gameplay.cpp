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
		Wall wall = initWall();

		while (!WindowShouldClose() && player.isAlive)
		{
			//Update
			playerMovment(player);
			playerScreenCollision(player);
			wallMovement(wall);
			changeRandomWall(wall);
			wallPlayerCollision(wall, player);
			//start Draw
			BeginDrawing();

			DrawRectangleLines(static_cast<int>(player.x), static_cast<int>(player.y), static_cast<int>(player.w), static_cast<int>(player.h), RED);
			DrawRectangleLines(static_cast<int>(wall.x), static_cast<int>(wall.y), static_cast<int>(wall.w), static_cast<int>(wall.h), YELLOW);
			DrawText("Ver: 0.1", versionTextX, versionTextY, 15, WHITE);
			ClearBackground(BLACK);

			//end Draw
			EndDrawing();
		}

		//De-Init
		CloseWindow();
	}
}