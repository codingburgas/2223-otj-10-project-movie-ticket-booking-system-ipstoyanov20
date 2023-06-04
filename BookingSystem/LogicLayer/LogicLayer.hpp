#pragma once
#include "pch.h"
#include "Login.hpp"
#include "SceneManager.hpp"
class LogicLayer : public Login, public SceneManager
{
public:
	LogicLayer();
	~LogicLayer();

	Data* data;
protected:
	bool isClicked(Vector2& mousePos, Rectangle& rect);
	bool isUnfocusedClick(Vector2& mousePos, Rectangle& rect);
	//bool validate(std::string username, std::string password);

	

	std::unordered_map<std::string,
		std::pair<
		std::pair<Rectangle, bool>, std::vector<Rectangle>
		>
	> menuFields;

	Vector2 mousePoint;
};

