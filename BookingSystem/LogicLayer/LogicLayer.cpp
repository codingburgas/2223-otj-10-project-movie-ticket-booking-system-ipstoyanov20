#include "pch.h"
#include "LogicLayer.hpp"
LogicLayer::LogicLayer()
{
	//data = Data::getInstance();
	inputFields = {
		{
				"Username", {0, Rectangle{0, 500, 400, 75}},
		},
		{
				"Password", {0, Rectangle{ 0, 650, 400, 75 }}
		}
	};
	submitButton = Rectangle{ 0, 800, 200, 75 };

	filmCard = {
		{"Filname", { {Texture2D(), 0}, Rectangle()}},
		{"Filname2", { {Texture2D(), 0}, Rectangle()}},
		{"Filname3", { {Texture2D(), 0}, Rectangle()}},
		{"Filname4", { {Texture2D(), 0}, Rectangle()}}
	};
	for (auto& [key, rect] : filmCard)
	{
		static int i = 1;
		rect.second = Rectangle{ 1500, (90.f + 75) * i, 200, 500};
		i++;
	}


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

//bool LogicLayer::validate(std::string username, std::string password)
//{
//	return data->select("Deni", "Osussogurnosta");
//}

bool LogicLayer::isClicked(Vector2& mousePos, Rectangle& rect)
{
	return CheckCollisionPointRec(mousePos, rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool LogicLayer::isUnfocusedClick(Vector2& mousePos, Rectangle& rect)
{
	return !CheckCollisionPointRec(mousePos, rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

LogicLayer::~LogicLayer()
{

}