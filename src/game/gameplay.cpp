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

			ClearBackground(BLACK);

			//end Draw
			EndDrawing();
		}

		//De-Init
		CloseWindow();
	}
}