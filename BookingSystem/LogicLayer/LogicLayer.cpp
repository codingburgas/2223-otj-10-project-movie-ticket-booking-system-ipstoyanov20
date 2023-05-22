#include "pch.h"
#include "LogicLayer.hpp"

LogicLayer::LogicLayer()
{
	data = Data::getInstance();
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
bool LogicLayer::isClicked(Vector2& mousePos, Rectangle& rect)
{
	return CheckCollisionPointRec(mousePos, rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

LogicLayer::~LogicLayer()
{
}