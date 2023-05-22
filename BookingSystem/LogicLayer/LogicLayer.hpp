#pragma once
#include "pch.h"
class LogicLayer
{
public:
	LogicLayer();
	~LogicLayer();

protected:
	Data* data;
	bool isClicked(Vector2& mousePos, Rectangle& rect);

	std::unordered_map<std::string,
		std::pair<
		std::pair<Rectangle, bool>, std::vector<Rectangle>
		>
	> menuFields;

	Vector2 mousePoint;
};

