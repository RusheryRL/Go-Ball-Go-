#include "gameplay.h"

#include "raylib.h"

#include "objects/player.h"
#include "objects/wall.h"
#include "windowManagment.h"

namespace GoBallGo
{
	void gameRun()
	{
		//init
		static Player player = initPlayer();
		static Wall wall[MAX_WALLS_IN_SCREEN] = {};
		static Texture2D backGround = LoadTexture("res/img/pixel_art_gradas.png");
		static Texture2D midGround = LoadTexture("res/img/pixel_art_corners.png");
		static Texture2D foreGround = LoadTexture("res/img/pixel_art_pasto.png");
		static float scrollingBack = 0.0f;
		static float scrollingMid = 0.0f;
		static float scrollingFore = 0.0f;

		for (int i = 0; i < MAX_WALLS_IN_SCREEN; i++)
		{
			wall[i] = initWall();
		}

		while (!WindowShouldClose() && player.isAlive)
		{
			//Background Update
			scrollingBack -= 0.1f;
			scrollingMid -= 0.5f;
			scrollingFore -= 1.0f;

			if (scrollingBack <= -backGround.width * 2) scrollingBack = 0;
			if (scrollingMid <= -midGround.width * 2) scrollingMid = 0;
			if (scrollingFore <= -foreGround.width * 2) scrollingFore = 0;

			//gameplay update
			playerMovment(player);
			playerScreenCollision(player);
			wallUpdate(wall, player);
			//start Draw
			BeginDrawing();
			ClearBackground(DARKGREEN);

			DrawTextureEx(backGround, { scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
			DrawTextureEx(backGround, {backGround.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

			DrawTextureEx(midGround,{ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
			DrawTextureEx(midGround,{ midGround.width * 2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

			DrawTextureEx(foreGround, { scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
			DrawTextureEx(foreGround, { foreGround.width * 2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);

			DrawRectangleLines(static_cast<int>(player.x), static_cast<int>(player.y), static_cast<int>(player.w), static_cast<int>(player.h), RED);
			drawWall(wall);

			//end Draw
			EndDrawing();
		}

		UnloadTexture(backGround);
		UnloadTexture(midGround);
		UnloadTexture(foreGround);

		CloseWindow();
	}
}