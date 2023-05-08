#pragma once
#include "lib/src/raylib.h"
class PresentationLayer
{
public:
	PresentationLayer();
	~PresentationLayer();
	void createWindow();
	void closeWindow();
private:
	bool isClicked(Vector2& mousePos, Rectangle& rect);
	bool dropdown;
	std::unordered_map<std::string, Rectangle> menuFields;
	std::vector<Rectangle> menuDropDowns;
	Vector2 mousePoint;
	float getWidthPercentageOf(float vl);
	float getHeightPercentageOf(float vl);
	void drawMenu();

};