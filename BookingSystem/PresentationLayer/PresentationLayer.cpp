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
	DrawText("C", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, LIGHTGRAY);
	EndDrawing();
}

void PresentationLayer::closeWindow()
{
	CloseWindow();
}