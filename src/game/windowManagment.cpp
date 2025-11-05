#include <iostream>

using namespace std;

#include "windowManagment.h"

namespace GoBallGo
{
	void mouseSelection(Vector2 mousePos, Button& button)
	{
		if (isMouseInButton(mousePos, button))
		{
			button.isPressed = true;
		}
		else
			button.isPressed = false;
	}

	bool isMouseInButton(Vector2 mousePos, Button button)
	{
		if (mousePos.x >= button.x && mousePos.x <= button.x + BUTTONS_WIDTH &&
			mousePos.y >= button.y && mousePos.y <= button.y + BUTTONS_HEIGHT)
			return true;
		else
			return false;
	}
}
