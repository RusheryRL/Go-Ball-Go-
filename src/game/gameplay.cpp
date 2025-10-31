#include "gameplay.h"

#include "raylib.h"

#include "windowManagment.h"
#include "objects/player.h"

namespace GoBallGo
{
	void GameRun()
	{
		InitWindow(screenWidth, screenHeight, "Go! Ball Go!");
		//Inits
		Player player = initPlayer();

		while (!WindowShouldClose())
		{
			//Update
			playerMovment(player);
			playerScreenCollision(player);
			//start Draw
			BeginDrawing();

			DrawRectangleLines(static_cast<int>(player.x), static_cast<int>(player.y), static_cast<int>(player.w), static_cast<int>(player.h), RED);

			ClearBackground(BLACK);

			//end Draw
			EndDrawing();
		}

		//De-Init
		CloseWindow();
	}
}