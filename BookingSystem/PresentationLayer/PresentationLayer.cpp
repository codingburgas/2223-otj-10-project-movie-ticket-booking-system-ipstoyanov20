#include "pch.h"
#include "PresentationLayer.hpp"

PresentationLayer::PresentationLayer()
{

	functions = {
		[](PresentationLayer* obj) { obj->drawMenu(); },
		[](PresentationLayer* obj) { obj->drawLogin(); },
	};
}

PresentationLayer::~PresentationLayer()
{
}

void PresentationLayer::createWindow()
{
	
	while (!WindowShouldClose())
	{
		 if (IsKeyPressed(KEY_A)) {
			MinimizeWindow();
			OpenURL("https://www.youtube.com");
		 }

		BeginDrawing();
			ClearBackground(BACKGROUND_ADMIN);
			mousePoint = GetMousePosition();
			functions[direction](this);
		EndDrawing();
	}
}

void PresentationLayer::drawLogin()
{
		
	DrawRectangleRounded(Rectangle{ GetScreenWidth() / 2.f - 1300 / 2, 50, 1300, GetScreenHeight() - 100.f}, 0.2, 0, SKYBLUE);
	//SUBMIT BUTTON
	DrawRectangleRounded(submitButton, 0.2, 0, DARKGRAY);
		if(CheckCollisionPointRec(mousePoint, submitButton)) DrawRectangleRounded(submitButton, 0.2, 0, GRAY);
	DrawText("Submit", submitButton.x + submitButton.width / 3.5,submitButton.y + 25, 30, BLACK);
	
	//validate
	/*if (isClicked(mousePoint, submitButton))
	{
		if (data->select(username, password))
		{
			direction = MENU;
		}
	}*/

	for (auto&[name, field] : inputFields)
	{
		field.second.x = GetScreenWidth() / 2.f - field.second.width / 2;
		DrawText(name.c_str(), field.second.x, field.second.y - 30, 30, DARKGRAY);
		DrawRectangleRounded(field.second, 0.2, 0, DARKGRAY);
		if(CheckCollisionPointRec(mousePoint, field.second)) DrawRectangleRounded(field.second, 0.2, 0, GRAY);

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
			DrawText(username, field.second.x + 20, field.second.y+20, 30, BLACK);
		}
		else if (name == "Password") {
			DrawText(Hiddenpassword, field.second.x + 20, field.second.y+20, 30, BLACK);
		}
	}
	
}

void PresentationLayer::drawMenu()
{
	DrawRectangleRounded(Rectangle{ 20, 50, 250, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	DrawRectangleRounded(Rectangle{ 550, 50, 1300, GetScreenHeight() - 100.f}, 0.2, 0, MENU_ADMIN);
	for (auto& [name, rect] : menuFields)
	{
		if (isClicked(mousePoint, rect.first.first) || rect.first.second)
		{

			int i = 0;
			for (auto& dropDownRect : rect.second)
			{
				dropDownRect = Rectangle{ rect.first.first.x + 250,rect.first.first.y + i * (rect.first.first.width / 2.5f),rect.first.first.width,rect.first.first.height };
				
				rect.first.second = !isClicked(mousePoint, dropDownRect);

				if (!rect.first.second) break;

				i++;

			}
			i = 0;
			for (auto& dropDownRect : rect.second)
			{
				
				DrawRectangleRounded(dropDownRect, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
				i++;

				DrawTextEx(Font(), (name + std::to_string(i)).c_str(), Vector2{dropDownRect.x + dropDownRect.width / 2.f - (20 / 2 + 3 * name.size() + 1), dropDownRect.y + dropDownRect.height / 2.f - (20 / 2)}, 20, 3, WHITE);
			}
		}
		if (CheckCollisionPointRec(mousePoint, rect.first.first))
		{
			DrawRectangleRounded(rect.first.first, 0.2, 0, MENU_TEXT_FIELDS_HOVER);
		}
		else
			DrawRectangleRounded(rect.first.first, 0.2, 0, MENU_TEXT_FIELDS);

		DrawTextEx(Font(), name.c_str(), Vector2{ rect.first.first.x + rect.first.first.width / 2.f - (20 / 2 + 3 * name.size()), rect.first.first.y + rect.first.first.height / 2.f - (20 / 2)}, 20, 3, WHITE);
	}
	////film
	for (auto& [name, rect] : filmCard)
	{
		DrawTexturePro(rect.first.first, rect.first.second.second, rect.second, {0, 0}, 0,  WHITE);
		if (isClicked(mousePoint, rect.second) || rect.first.second.first)
		{
			//DrawTextEx(Font(), (name + std::to_string(i)).c_str(), Vector2{ rect.second.x + rect.second.width / 2.f - (20 / 2 + 3 * name.size() + 1), dropDownRect.y + dropDownRect.height / 2.f - (20 / 2) }, 20, 3, WHITE);
		}
		if (CheckCollisionPointRec(mousePoint, rect.second))
		{
			DrawTexturePro(rect.first.first, rect.first.second.second, rect.second, {0, 0}, 0, Fade(BLACK, 0.5));
		}
		//else
			//DrawTextureRec(rect.first.first, rect.second, Vector2{rect.second.x, rect.second.y},BLANK);

		//DrawTextEx(Font(), name.c_str(), Vector2{ rect.second.x + rect.second.width / 2.f - (20 / 2 + 3 * name.size()), rect.second.y + rect.second.height / 2.f - (20 / 2) }, 20, 3, WHITE);
		//DrawTextureRec(rect.first.first, rect.second, Vector2{rect.second.x, rect.second.y},BLANK);
	}

}

void PresentationLayer::closeWindow()
{
	CloseWindow();
}