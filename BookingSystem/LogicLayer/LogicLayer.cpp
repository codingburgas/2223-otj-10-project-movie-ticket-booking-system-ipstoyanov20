#include "pch.h"
#include "LogicLayer.hpp"
LogicLayer::LogicLayer()
{
	InitWindow(0, 0, "MovieBookingSystem");
	SetTargetFPS(60);
	ToggleFullscreen();
	//data = Data::getInstance();
	inputFields = {
		{
				"Username", {0, Rectangle{0, 500, 400, 75}},
		},
		{
				"Password", {0, Rectangle{ 0, 650, 400, 75 }}
		}
	};
	submitButton = Rectangle{ GetScreenWidth() / 2.f - submitButton.width / 2, 800, 200, 75 };

	filmCard = {
		{"FastX", { {Texture2D(), {0,Rectangle()}}, Rectangle()}},
		{"Name", { {Texture2D(), {0,Rectangle()}}, Rectangle()}},
		{"Filname2", { {Texture2D(), {0,Rectangle()}}, Rectangle()}},
		{"Filname3", { {Texture2D(), {0,Rectangle()}}, Rectangle()}},
	};
	for (auto& [key, rect] : filmCard)
	{

		static int i = 0;

		static int right = 0;
		static int down = 0;

			rect.second = Rectangle{ 900.f + right, 100.f + down, 200, 250};
			rect.first.second.second = Rectangle{ 0, 0, 200, 250};

			rect.first.first = LoadTexture("../assests/fast.png");

			rect.first.first.width = rect.second.width;
			rect.first.first.height = rect.second.height;
		i++;

		std::cout << "Fourth " << rect.second.x;
		if (i % 2 == 0 && i > 0) { right += 210, down = 0; }
		else { down += 280; }
	}


	menuFields = {

		{"City", {{Rectangle(), 0}, {Rectangle(), Rectangle()}} },
		{"Cinema", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
		{"Hall", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
		{"Time", {{Rectangle(), 0}, {Rectangle(), Rectangle()}}},
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