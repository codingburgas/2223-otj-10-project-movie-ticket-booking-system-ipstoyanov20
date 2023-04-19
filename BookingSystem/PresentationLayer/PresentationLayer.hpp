#pragma once
class PresentationLayer
{
public:
	PresentationLayer();
	~PresentationLayer();
	void createWindow();
	void closeWindow();
private:
	void draw();

};