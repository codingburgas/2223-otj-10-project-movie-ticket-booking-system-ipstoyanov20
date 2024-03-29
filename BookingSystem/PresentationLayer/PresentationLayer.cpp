#include "pch.h"
#include "PresentationLayer.hpp"

PresentationLayer::PresentationLayer()
{

	functions = {
		[](PresentationLayer* obj) { obj->drawLogin(); },
		[](PresentationLayer* obj) { obj->drawMenu(); },
		[](PresentationLayer* obj) { obj->drawSeats(); },
		[](PresentationLayer* obj) { obj->drawTicket(); }
	};
}

PresentationLayer::~PresentationLayer()
{
}

void PresentationLayer::drawSingInButton()
{
	DrawRectangleRounded(visitSiteButton, 0.2, 0, MENU_ADMIN);
	if (CheckCollisionPointRec(mousePoint, visitSiteButton)) DrawRectangleRounded(visitSiteButton, 0.2, 0, MENU_ADMIN_HOVER);

	DrawText("Sing up", visitSiteButton.x + visitSiteButton.width / 3.5, visitSiteButton.y + 25, 30, BLACK);
	if (isClicked(mousePoint, visitSiteButton)) {
		MinimizeWindow();
		OpenURL("https://movie-system.vercel.app/");
	}
}

void PresentationLayer::createWindow()
{
	
	while (!WindowShouldClose() && !quit)
	{

		BeginDrawing();
			ClearBackground(BACKGROUND_ADMIN);
			mousePoint = GetMousePosition();
			functions[direction](this);
		EndDrawing();
	}
}

void PresentationLayer::drawLogin()
{
		
	DrawRectangleRounded(Rectangle{ GetScreenWidth() / 2.f - 1300 / 2, 50, 1300, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	DrawTexture(icon, 850, 200, WHITE);
	drawSingInButton();
	//SUBMIT BUTTON
	DrawRectangleRounded(submitButton, 0.2, 0, MENU_TEXT_FIELDS);
		if(CheckCollisionPointRec(mousePoint, submitButton)) DrawRectangleRounded(submitButton, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
	DrawText("Submit", submitButton.x + submitButton.width / 3.5,submitButton.y + 25, 30, WHITE);
	
	for (auto& [label, boolean] : incorrectInputLabel) {
		if (boolean)	 DrawText(label.c_str(),850, 750, 30, Fade(RED, 0.5));


		if (isClicked(mousePoint, submitButton))
		{
			boolean = !data->select(username, password);
			if (!boolean)
			{
				direction = MENU;
			}
		}
	}

	for (auto&[name, field] : inputFields)
	{
		field.second.x = GetScreenWidth() / 2.f - field.second.width / 2;
		DrawText(name.c_str(), field.second.x, field.second.y - 30, 30, MENU_TEXT_FIELDS);
		DrawRectangleRounded(field.second, 0.2, 0, MENU_TEXT_FIELDS);
		if(CheckCollisionPointRec(mousePoint, field.second)) DrawRectangleRounded(field.second, 0.2, 0, MENU_TEXT_FIELDS_HOVER);

		//check
		
		if(!field.first) field.first = isClicked(mousePoint, field.second);

		if ( field.first && name == "Username") {
			getUserName(username, letterCountUsername);
			field.first = !isUnfocusedClick(mousePoint, field.second);
		}else if (field.first && name == "Password") {
			getPass(Hiddenpassword, letterCountPassword);
			field.first = !isUnfocusedClick(mousePoint, field.second);
		}
		if (name == "Username") {
			DrawText(username, field.second.x + 20, field.second.y+20, 30, WHITE);
		}
		else if (name == "Password") {
			DrawText(Hiddenpassword, field.second.x + 20, field.second.y+20, 30,WHITE);
		}
	}
	
	
}

void PresentationLayer::drawMenu()
{
	DrawRectangleRounded(Rectangle{ 20, 180, 300, GetScreenHeight() - 250.f}, 0.2, 0, MENU_ADMIN);
	DrawRectangleRounded(Rectangle{ 650, 180, 1000, GetScreenHeight() - 250.f}, 0.2, 0, MENU_ADMIN);

	DrawTexture(avatar, 100, 10, WHITE);

	DrawText("Welcome, ", 50, 130, 30, WHITE);
	DrawText("Choose Film", 950, 250, 50, BLACK);
	DrawText(username, 200, 130, 30, WHITE);

	for (auto& [name, rect] : menuFields)
	{
		if (isClicked(mousePoint, rect.second.first.first) || rect.second.first.second)
		{

			int i = 0;
			for (auto& dropDownRect : rect.second.second)
			{
				dropDownRect = Rectangle{ rect.second.first.first.x + 250,rect.second.first.first.y + i * (rect.second.first.first.width / 2.5f),rect.second.first.first.width,rect.second.first.first.height };
				
				rect.second.first.second = !isClicked(mousePoint, dropDownRect);

				if (!rect.second.first.second)
				{
					ticketFields[name] = rect.first.first[i];
					rect.first.second.first = i;
					rect.first.second.second = 1;
					break;
				}

				i++;

			}
			i = 0;
			for (auto& dropDownRect : rect.second.second)
			{
				(i == rect.first.second.first && rect.first.second.second) ? DrawRectangleRounded(dropDownRect, 0.2, 0, BLACK) :
					DrawRectangleRounded(dropDownRect, 0.2, 0, MENU_TEXT_FIELDS_HOVER);

				 
				DrawTextEx(Font(), rect.first.first[i].c_str(), Vector2{dropDownRect.x + dropDownRect.width / 2.f - (rect.first.first[i].size() / 3.5f * 20), dropDownRect.y + dropDownRect.height / 2.f - (20 / 2)}, 20, 3, WHITE);
				i++;
			}
		}
		if (CheckCollisionPointRec(mousePoint, rect.second.first.first))
		{
			DrawRectangleRounded(rect.second.first.first, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
		}
		else
			DrawRectangleRounded(rect.second.first.first, 0.2, 0, MENU_TEXT_FIELDS);
		
		DrawTextEx(Font(), name.c_str(), Vector2{ rect.second.first.first.x + rect.second.first.first.width / 2.f - (name.size() / 3.5f * 20), rect.second.first.first.y + rect.second.first.first.height / 2.f - 20 / 2}, 20, 3, WHITE);
	}
	////film
	for (auto& [name, rect] : filmCard)
	{
		DrawTexturePro(rect.first.first, rect.first.second.second, rect.second, { 0, 0 }, 0, WHITE);
		if (isClicked(mousePoint, rect.second) || rect.first.second.first)
		{
			seatNameFromClick = name;
			direction = SEATS;
		}
			
		if (CheckCollisionPointRec(mousePoint, rect.second))
		{
			DrawTexturePro(rect.first.first, rect.first.second.second, rect.second, { 0, 0 }, 0, Fade(BLACK, 0.5));
		}
	}

}

void PresentationLayer::drawSeats()
{
	//previous button
	DrawRectangleRounded(previousButton, 0.2, 0, MENU_ADMIN);
	if (CheckCollisionPointRec(mousePoint, previousButton)) DrawRectangleRounded(previousButton, 0.2, 0, MENU_ADMIN_HOVER);
	isClicked(mousePoint, previousButton) ? direction = Scenes(int(direction - 1)) : true;
	DrawText("Previous", previousButton.x + 45, previousButton.y + 25, 30, BLACK);

	DrawRectangleRounded(submitSeatsButton, 0.2, 0, MENU_ADMIN);
	if (CheckCollisionPointRec(mousePoint, submitSeatsButton)) DrawRectangleRounded(submitSeatsButton, 0.2, 0, MENU_ADMIN_HOVER);
	if (isClicked(mousePoint, submitSeatsButton)) direction = TICKET;
	DrawText("Submit", submitSeatsButton.x + submitSeatsButton.width / 3.5, submitSeatsButton.y + 25, 30, BLACK);


	//film poster
	DrawTexture(filmCard[seatNameFromClick].first.first, GetScreenWidth() / 2 - filmCard[seatNameFromClick].first.first.width / 2, 50, WHITE);

	//rect for seats
	DrawRectangleRounded(Rectangle{ GetScreenWidth() / 2.f - 475, 400, 950, 550}, 0.1, 0, MENU_ADMIN);
	//Rect for header text
	DrawRectangleRounded(Rectangle{ GetScreenWidth() / 2.f - 400, 310, 800, 60}, 0.1, 0, MENU_ADMIN);

	DrawText(("Choose seats for " + seatNameFromClick).c_str(), GetScreenWidth() / 2.f - (("Choose seat for " + seatNameFromClick).size() / 3.5 * 40), 320, 40, BLACK);

	for (int rows = 0; rows < sizeof(seatsLeft) / sizeof(seatsLeft[0]); rows++)
	{

		for (int cols = 0; cols < sizeof(seatsLeft[rows]) / sizeof(seatsLeft[rows][0]); cols++)
		{
			if (isClicked(mousePoint, seatsLeft[rows][cols]) )
			{
				SelectedSeatsLeft[rows][cols] = 1;
			}
			CheckCollisionPointRec(mousePoint, seatsLeft[rows][cols]) ? DrawRectangleRounded(seatsLeft[rows][cols], 0.2, 0, MENU_TEXT_FIELDS_HOVER) : DrawRectangleRounded(seatsLeft[rows][cols], 0.2, 0, BLACK);
			if(SelectedSeatsLeft[rows][cols]) DrawRectangleRounded(seatsLeft[rows][cols], 0.2, 0, MENU_ADMIN_HOVER);
			DrawText(std::to_string(cols + 1).c_str(), seatsLeft[rows][cols].x + 30, seatsLeft[rows][cols].y + 30, 15, WHITE);
		}
	}
	
	for (int rows = 0; rows < sizeof(seatsRight) / sizeof(seatsRight[0]); rows++)
	{

		for (int cols = 0; cols < sizeof(seatsRight[rows]) / sizeof(seatsRight[rows][0]); cols++)
		{

			if (isClicked(mousePoint, seatsRight[rows][cols]))
			{
				SelectedSeatsRight[rows][cols] = 1;
			}
			CheckCollisionPointRec(mousePoint, seatsRight[rows][cols]) ? DrawRectangleRounded(seatsRight[rows][cols], 0.2, 0, MENU_TEXT_FIELDS_HOVER) : DrawRectangleRounded(seatsRight[rows][cols], 0.2, 0, BLACK);
			if(SelectedSeatsRight[rows][cols]) DrawRectangleRounded(seatsRight[rows][cols], 0.2, 0, MENU_ADMIN_HOVER);
			DrawText(std::to_string(cols + 5).c_str(), seatsRight[rows][cols].x + 30, seatsRight[rows][cols].y + 30, 15, WHITE);

		}
	}

	
}
void PresentationLayer::drawTicket()
{
	
	DrawRectangleRounded(Rectangle{ GetScreenWidth() / 2.f - 500, GetScreenHeight() / 2.f - 250, 1000, 500}, 0.2, 0, MENU_ADMIN);
	DrawText("Your Ticket:", GetScreenWidth() / 2.f - 450, GetScreenHeight() / 2.f - 200, 40, BLACK);

	DrawText(("Movie: " + seatNameFromClick).c_str(), GetScreenWidth() / 2.f - 450, GetScreenHeight() / 2.f - 100, 30, BLACK);
	
	int down = 0;
	for (const auto& [name, value] : ticketFields)
	{
		DrawText((name + ": " + value).c_str(), GetScreenWidth() / 2.f - 450, GetScreenHeight() / 2.f - 50 + down, 30, BLACK);
		down+= 50;
	}
	down = 0;
	//draw which seats are selected
	DrawText("Left part of seats: ", GetScreenWidth() / 2.f - 450, GetScreenHeight() / 2.f + 100, 30, BLACK);
	for (int rows = 0; rows < sizeof(seatsLeft) / sizeof(seatsLeft[0]); rows++)
	{
		//std::cout << sizeof(seatsLeft) / sizeof(seatsLeft[0]) << std::endl;
		for (int cols = 0; cols < sizeof(seatsLeft[rows]) / sizeof(seatsLeft[rows][0]); cols++)
		{
			
			if (SelectedSeatsLeft[rows][cols])
			{
				DrawText(("row: " + std::to_string(rows + 1) + " seat: " + std::to_string(cols + 1) + " - ").c_str(), GetScreenWidth() / 2.f - 100 + down, GetScreenHeight() / 2.f + 100, 25, BLACK);
				down += 210;
			}
			
		}
	}
	down = 0;
	DrawText("Right part of seats: ", GetScreenWidth() / 2.f - 450, GetScreenHeight() / 2.f + 150, 30, BLACK);
	for (int rows = 0; rows < sizeof(seatsRight) / sizeof(seatsRight[0]); rows++)
	{

		for (int cols = 0; cols < sizeof(seatsRight[rows]) / sizeof(seatsRight[rows][0]); cols++)
		{
			
			if (SelectedSeatsRight[rows][cols])
			{
				DrawText(("row: " + std::to_string(rows + 1) + " seat: " + std::to_string(cols + 5) + " - ").c_str(), GetScreenWidth() / 2.f - 100 + down, GetScreenHeight() / 2.f + 150, 25, BLACK);
				down += 210;
			}
		}
		
	}
	DrawRectangleRounded(enjoy, 0.2, 0, MENU_ADMIN);
	if (isClicked(mousePoint, enjoy)) quit = 1;
	DrawText("Enjoy", enjoy.x + 55, enjoy.y + 25, 30, BLACK);

}

void PresentationLayer::closeWindow()
{
	CloseWindow();
}