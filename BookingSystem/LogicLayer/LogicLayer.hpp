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
	
	Rectangle visitSiteButton;
	Texture2D avatar;
	
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

	Vector2 mousePoint;

	Rectangle seatsLeft[5][4];
	Rectangle seatsRight[5][4];

	std::vector< std::vector<bool>> SelectedSeatsLeft;
	std::vector< std::vector<bool>> SelectedSeatsRight;

	std::string seatNameFromClick;

	Rectangle submitSeatsButton;

	Rectangle previousButton;
	Rectangle nextButton;

	Rectangle enjoy;

	bool quit = false;

	std::unordered_map<std::string, std::string> ticketFields;

};

