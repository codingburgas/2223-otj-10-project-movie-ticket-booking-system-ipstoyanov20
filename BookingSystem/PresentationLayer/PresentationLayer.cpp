#include "pch.h"
#include "PresentationLayer.hpp"

PresentationLayer::PresentationLayer()
{
	menuFields = {

		{"City", {{Rectangle(), 0}, {Rectangle(), Rectangle()}} },
		{"Cinema", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
		{"Hall", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
		{"Time", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
		{"Film", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
	};
	for (auto& [key, rect] : menuFields)
	{
		static int i = 1;
		rect.first.first = Rectangle{ 40, (90.f + 75) * i, 200, 75 };
		i++;
	}
}

PresentationLayer::~PresentationLayer()
{
}

void PresentationLayer::createWindow()
{
	InitWindow(0, 0, "MovieBookingSystem");
	SetTargetFPS(60);
	ToggleFullscreen();
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

//void PresentationLayer::drawMenu()
//{
//
//}
void PresentationLayer::drawMenu()
{
	BeginDrawing();
	DrawRectangleRounded(Rectangle{ 20, 50, 250, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	DrawRectangleRounded(Rectangle{ 550, 50, 1300, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	for (auto& [name, rect] : menuFields)
	{
		if (isClicked(mousePoint, rect.first.first) || rect.first.second)
		{

			int i = 0;
			for (auto& dropDownRect : rect.second)
			{
				dropDownRect = Rectangle{ rect.first.first.x + 250,rect.first.first.y + i * (rect.first.first.width / 2.5f),rect.first.first.width,rect.first.first.height };
				
				rect.first.second = !isClicked(mousePoint, dropDownRect);

				if (!rect.first.second) break;

				i++;

			}
			i = 0;
			for (auto& dropDownRect : rect.second)
			{
				
				DrawRectangleRounded(dropDownRect, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
				i++;

				DrawTextEx(Font(), (name + std::to_string(i)).c_str(), Vector2{dropDownRect.x + dropDownRect.width / 2.f - (20 / 2 + 3 * name.size() + 1), dropDownRect.y + dropDownRect.height / 2.f - (20 / 2)}, 20, 3, WHITE);
			}
		}
		if (CheckCollisionPointRec(mousePoint, rect.first.first))
		{
			DrawRectangleRounded(rect.first.first, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
		}
		else
			DrawRectangleRounded(rect.first.first, 0.2, 0, MENU_TEXT_FIELDS);

		DrawTextEx(Font(), name.c_str(), Vector2{ rect.first.first.x + rect.first.first.width / 2.f - (20 / 2 + 3 * name.size()), rect.first.first.y + rect.first.first.height / 2.f - (20 / 2)}, 20, 3, WHITE);
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