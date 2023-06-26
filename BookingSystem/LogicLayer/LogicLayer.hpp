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

	//strings
	std::string seatNameFromClick;

	//booleans

	bool quit = false;
	bool isClicked(Vector2& mousePos, Rectangle& rect);
	bool isUnfocusedClick(Vector2& mousePos, Rectangle& rect);

	//unorderd maps
	std::unordered_map 
	< 
		std::string,
		std::pair 
		<
				std::pair 
				< 
					Texture2D, 
					std::pair<bool, Rectangle> 
				>,Rectangle 
		>
	> filmCard;

	std::unordered_map<std::string,
		std::pair<std::pair<std::vector<std::string>, std::pair<int, bool>>, 
			std::pair<
				std::pair<Rectangle, bool>, std::vector<Rectangle>
			>
		>
	> menuFields;

	std::unordered_map<std::string, std::string> ticketFields;

	//Rectangles
	Rectangle visitSiteButton;
	Rectangle seatsLeft[5][4];
	Rectangle seatsRight[5][4];
	Rectangle submitSeatsButton;
	Rectangle nextButton;
	Rectangle previousButton;
	Rectangle enjoy;

	//Textures
	Texture2D avatar;

	//std::vectors
	std::vector< std::vector<bool>> SelectedSeatsLeft;
	std::vector< std::vector<bool>> SelectedSeatsRight;

	//Vector2
	Vector2 mousePoint;



};

