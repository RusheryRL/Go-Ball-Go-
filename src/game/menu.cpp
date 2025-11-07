#include "menu.h"

#include "windowManagment.h"
#include "gameplay.h"
#include "credits.h"

namespace GoBallGo
{
	void openMenu()
	{
		InitWindow(screenWidth, screenHeight, "Go! Ball Go!");
		//Inits
		const int versionTextX = GetScreenWidth() - 65;
		const int versionTextY = GetScreenHeight() - 15;
		Button playButton = initButton(screenWidth / 2, screenHeight / 6, BUTTONS_WIDTH, BUTTONS_HEIGHT, false);
		Button creditsButton = initButton(screenWidth / 2, screenHeight / 2, BUTTONS_WIDTH, BUTTONS_HEIGHT, false);
		Button exitButton = initButton(screenWidth / 2, screenHeight / 3, BUTTONS_WIDTH, BUTTONS_HEIGHT, false);
		Vector2 mouse = {};

		while (!WindowShouldClose() && !exitButton.isPressed)
		{
			//update
			mouseClick(mouse);
			mouseSelection(mouse,playButton);
			mouseSelection(mouse, creditsButton);
			mouseSelection(mouse, exitButton);

			if (playButton.isPressed)
			{
				gameRun();
				playButton.isPressed = false;
			}
			if (creditsButton.isPressed)
			{
				creditsScreen();
				creditsButton.isPressed = false;
			}

			//start Draw
			BeginDrawing();
			DrawText("Ver: 0.3", versionTextX, versionTextY, 15, WHITE);
			DrawRectangle(static_cast<int>(playButton.x), static_cast<int>(playButton.y), static_cast<int>(playButton.w), static_cast<int>(playButton.h), GREEN);
			DrawRectangle(static_cast<int>(creditsButton.x), static_cast<int>(creditsButton.y), static_cast<int>(creditsButton.w), static_cast<int>(creditsButton.h), YELLOW);
			DrawRectangle(static_cast<int>(exitButton.x), static_cast<int>(exitButton.y), static_cast<int>(exitButton.w), static_cast<int>(exitButton.h), RED);
			ClearBackground(BLACK);
			//end Draw
			EndDrawing();
		}
		// De-Init
		CloseWindow();
	}
	void mouseClick(Vector2& mouse)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			mouse = GetMousePosition();
		}
	}
}
