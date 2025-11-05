#include "credits.h"

#include "windowManagment.h"
#include "menu.h"

namespace GoBallGo
{
	void creditsScreen()
	{
		//inits
		Button exitButton = initButton(screenWidth / 2, screenHeight - (screenHeight / 10), BUTTONS_WIDTH, BUTTONS_HEIGHT, false);
		Vector2 mouse = {};

		while (!WindowShouldClose() && !exitButton.isPressed)
		{
			//update
			mouseClick(mouse);
			mouseSelection(mouse, exitButton);

			if (exitButton.isPressed)
			{
				openMenu();
			}

			//start Draw
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Game Developed by: Juan Pablo 'Rushery' Pivetta", screenWidth / 3, screenHeight / 2, 20, WHITE);
			DrawRectangleLines(static_cast<int>(exitButton.x), static_cast<int>(exitButton.y), static_cast<int>(exitButton.w), static_cast<int>(exitButton.h), RED);

			//end Draw
			EndDrawing();
		}
		CloseWindow();
	}
}
