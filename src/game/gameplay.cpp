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
			//FPS
#ifdef _DEBUG
			DrawFPS(0, 0);
#endif _DEBUG

			//Update
			
			//start Draw
			BeginDrawing();

			ClearBackground(BLACK);

			//end Draw
			EndDrawing();
		}

		//De-Init
		CloseWindow();
	}
}