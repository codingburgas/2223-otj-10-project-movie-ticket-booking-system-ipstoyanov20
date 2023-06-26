#pragma once
#include "pch.h"
class PresentationLayer : public LogicLayer
{
public:
	PresentationLayer();
	~PresentationLayer();
	void createWindow();
	void closeWindow();
private:
	void drawLogin();
	void drawMenu();
	void drawSeats();
	void drawSingInButton();
	void drawTicket();

	std::vector<std::function<void(PresentationLayer*)>> functions;
};