#pragma once

#include "raylib.h"

namespace GoBallGo
{
	const int playerLivesX = GetScreenWidth() - (GetScreenWidth() / 10);
	const int playerLivesY = GetScreenHeight() - (GetScreenHeight() / 10);

	void GameRun();
}