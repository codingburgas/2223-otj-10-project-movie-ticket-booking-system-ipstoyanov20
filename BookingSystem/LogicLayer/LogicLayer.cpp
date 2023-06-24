#include "pch.h"
#include "LogicLayer.hpp"
LogicLayer::LogicLayer()
{
	InitWindow(0, 0, "MovieBookingSystem");
	SetTargetFPS(60);
	//ToggleFullscreen();
	data = Data::getInstance();
	inputFields = {
		{
				"Username", {0, Rectangle{0, 500, 400, 75}},
		},
		{
				"Password", {0, Rectangle{ 0, 650, 400, 75 }}
		}
	};
	submitButton = Rectangle{ GetScreenWidth() / 2.f - submitButton.width / 2, 800, 200, 75 };

	submitSeatsButton = Rectangle{ GetScreenWidth() / 2.f - 100, 965, 200, 75 };

	visitSiteButton = Rectangle{ 30, 50, 225, 75 };


	SelectedSeatsLeft.resize(5);
	for(auto&cols: SelectedSeatsLeft) cols.resize(4);
	
	SelectedSeatsRight.resize(5);
	for(auto&cols:SelectedSeatsRight) cols.resize(4);

	icon = LoadTexture("../assests/cinemaIcon.png");
	icon.width = 200;
	icon.height = 200;

	avatar = LoadTexture("../assests/avatar.png");
	avatar.width = 150;
	avatar.height = 150;

	filmCard = {
		{"Fast X", { {LoadTexture("../assests/fast.png") , {0,Rectangle()}}, Rectangle()}},
		{"Transformers", { {LoadTexture("../assests/trans.png") , {0,Rectangle()}}, Rectangle()}},
		{"Flash", { {LoadTexture("../assests/flash.png"), {0,Rectangle()}}, Rectangle()}},
		{"Elements", { {LoadTexture("../assests/elements.png"), {0,Rectangle()}}, Rectangle()}},
	};
	for (auto& [key, rect] : filmCard)
	{

		static int i = 0;

		static int right = 0;
		static int down = 0;

			rect.second = Rectangle{ 950.f + right, 350.f + down, 200, 250};
			rect.first.second.second = Rectangle{ 0, 0, 200, 250};

			rect.first.first.width = rect.second.width;
			rect.first.first.height = rect.second.height;
		i++;

		if (i % 2 == 0 && i > 0) { right += 210, down = 0; }
		else { down += 280; }
	}

	for (int rows = 0;rows<	sizeof(seatsLeft) / sizeof(seatsLeft[0]); rows++)
	{
		int right = 0;
		static int down = 0;

		for (int cols = 0; cols < sizeof(seatsLeft[rows]) / sizeof(seatsLeft[rows][0]); cols++)
		{

			seatsLeft[rows][cols] = Rectangle{ 550.f + right, 450.f + down, 70, 70 };
			right += 100;
		}
		down += 100;
	}

	for (int rows = 0; rows < sizeof(seatsRight) / sizeof(seatsRight[0]); rows++)
	{
		int right = 0;
		static int down = 0;

		for (int cols = 0; cols < sizeof(seatsRight[rows]) / sizeof(seatsRight[rows][0]); cols++)
		{

			seatsRight[rows][cols] = Rectangle{ 1000.f + right, 450.f + down, 70, 70 };
			right += 100;
		}
		down += 100;
	}

	incorrectInputLabel = {
		{"Incorrect try again", 0}
	};
	

	menuFields = {
		{"City", 
			{
				{
					{"Burgas", "Sofia"}, {0,0}
				},
				{
					{Rectangle(), 0}, 
					{Rectangle(), Rectangle()}
				}
			}
		},
		{"Hall", {{{"3", "4"}, {0,0}}, {{Rectangle(), 0}, {Rectangle(), Rectangle()}}}},
		{"Projections", {{{"12:30pm", "14:00pm", "18:00pm"}, {0,0}}, {{Rectangle(), 0}, {Rectangle(),Rectangle(), Rectangle()}}}},
	};
	for (auto& [key, rect] : menuFields)
	{
		static int down = 0;
		rect.second.first.first = Rectangle{ 60, 280.f + down, 200, 75 };
		down += 180;
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
	UnloadTexture(icon);
	UnloadTexture(avatar);
}