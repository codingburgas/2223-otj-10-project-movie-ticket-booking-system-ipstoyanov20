#include "pch.h"
#include "PresentationLayer.hpp"

PresentationLayer::PresentationLayer()
{
}

PresentationLayer::~PresentationLayer()
{
}

void PresentationLayer::createWindow()
{
	InitWindow(0, 0, "raylib [core] example - basic window");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		draw();
	}
}

void PresentationLayer::draw()
{
	BeginDrawing();
	ClearBackground(DARKGRAY);
	DrawRectangleRounded(Rectangle{20, 50, GetScreenWidth() - 40.f, GetScreenHeight() - 100.f }, 0.2, 0, GRAY);
	DrawText("C", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, LIGHTGRAY);
	EndDrawing();
}

void PresentationLayer::closeWindow()
{
	CloseWindow();
}

float PresentationLayer::getWidthPercentageOf(float value)
{
	return GetScreenWidth() / value;
}
float PresentationLayer::getHeightPercentageOf(float value)
{
	return GetScreenHeight() / value;
}