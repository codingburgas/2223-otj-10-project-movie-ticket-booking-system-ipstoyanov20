#pragma once
#include "pch.h"
class PresentationLayer
{
public:
	PresentationLayer();
	~PresentationLayer();
	void createWindow();
	void closeWindow();
private:
	bool isClicked(Vector2& mousePos, Rectangle& rect);

	std::unordered_map<std::string, 
		std::pair<
		std::pair<Rectangle, bool>, std::vector<Rectangle>
		>
	> menuFields;

	Vector2 mousePoint;
	void drawMenu();

};