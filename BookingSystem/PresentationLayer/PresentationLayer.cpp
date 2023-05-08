#include "pch.h"
#include "PresentationLayer.hpp"

PresentationLayer::PresentationLayer()
{
	menuFields = {
		{"City", Rectangle()},
		{"Cinema", Rectangle()},
		{"Hall", Rectangle()},
		{"Film", Rectangle()},
		{"Time", Rectangle()},

	};
	menuDropDowns = { Rectangle(), Rectangle() };
	for (auto& [key, rect] : menuFields)
	{
		static int i = 1;
		rect = Rectangle{ 40, (30.f + 75) * i, 200, 75 };
		i++;
	}
	dropdown = 0;
}

PresentationLayer::~PresentationLayer()
{
}

void PresentationLayer::createWindow()
{
	InitWindow(0, 0, "MovieBookingSystem");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		mousePoint = GetMousePosition();
		ClearBackground(BACKGROUND_ADMIN);
		drawMenu();
	}
}
bool PresentationLayer::isClicked(Vector2& mousePos,Rectangle&rect)
{
	if (CheckCollisionPointRec(mousePos, rect))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return true;
		}
	}
}
void PresentationLayer::drawMenu()
{
	BeginDrawing();
	DrawRectangleRounded(Rectangle{ 20, 50, 250, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	DrawRectangleRounded(Rectangle{ 550, 50, 1300, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	for (auto& [name, rect] : menuFields)
	{
		if (isClicked(mousePoint, rect) || CheckCollisionPointRec(mousePoint, rect))
		{

			int i = 0;
			for (auto& dropDownRect : menuDropDowns)
			{
				
				dropdown = !isClicked(mousePoint, dropDownRect);
				dropDownRect = Rectangle{ rect.x + 250,rect.y + i * (rect.width / 2),rect.width,rect.height };
				DrawRectangleRounded(dropDownRect, 0.2, 0, MENU_TEXT_FIELDS_HOVER);

				i++;

				DrawTextEx(Font(), (name + std::to_string(i)).c_str(), Vector2{dropDownRect.x + dropDownRect.width / 2.f - (20 / 2 + 3 * name.size() + 1), dropDownRect.y + dropDownRect.height / 2.f - (20 / 2)}, 20, 3, WHITE);
			}
		}
		if (CheckCollisionPointRec(mousePoint, rect))
		{
			DrawRectangleRounded(rect, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
		}
		else
			DrawRectangleRounded(rect, 0.2, 0, MENU_TEXT_FIELDS);

		DrawTextEx(Font(), name.c_str(), Vector2{rect.x + rect.width / 2.f - (20 / 2 + 3 * name.size()), rect.y + rect.height / 2.f - (20 / 2)}, 20, 3, WHITE);
	}

	EndDrawing();
}

void PresentationLayer::closeWindow()
{
	CloseWindow();
}

float PresentationLayer::getWidthPercentageOf(float value)
{
	return (GetScreenWidth() / value);
}
float PresentationLayer::getHeightPercentageOf(float value)
{
	return GetScreenHeight() / value;
}