#pragma once
class PresentationLayer
{
public:
	PresentationLayer();
	~PresentationLayer();
	void createWindow();
	void closeWindow();
private:
	float getWidthPercentageOf(float vl);
	float getHeightPercentageOf(float vl);
	void draw();

};