#include "pch.h"
#include "Login.hpp"

void Login::getUserName(char input[MAX_INPUT], int& letterCount)
{
	
	int key = GetCharPressed();
	// Check if more characters have been pressed on the same frame
	while (key > 0)
	{
		if (key >= 32 && key <= 125 && letterCount < MAX_INPUT)
		{
			input[letterCount] = (char)key;
			input[letterCount + 1] = '\0';
			letterCount++;
		}

		key = GetCharPressed();  // Check next character in the queue
	}

	if (IsKeyPressed(KEY_BACKSPACE))
	{
		letterCount--;
		if (letterCount < 0) letterCount = 0;
		input[letterCount] = '\0';
	}
}
void Login::getPass(char input[MAX_INPUT], int&letterCount)
{

	int key = GetCharPressed();
	// Check if more characters have been pressed on the same frame
	while (key > 0)
	{
		if (key >= 32 && key <= 125 && letterCount < MAX_INPUT)
		{
			password += (char)key;
			input[letterCount] = (char)'*';
			input[letterCount + 1] = '\0';
			letterCount++;
		}

		key = GetCharPressed();  // Check next character in the queue
	}

	if (IsKeyPressed(KEY_BACKSPACE))
	{
		letterCount--;
		if (letterCount < 0) letterCount = 0;
		input[letterCount] = '\0';
	}
}