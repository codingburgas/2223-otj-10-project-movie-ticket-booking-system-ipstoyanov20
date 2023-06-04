#pragma once
#include "pch.h"
#define MAX_INPUT 10
class Login
{
	public:
		
		// variables for username and password (vectors of chars) and ractangles for login form (userbname and password fields) also title for form and labels for input fields
	protected:
		char username[MAX_INPUT + 1] = "\0";
		char Hiddenpassword[MAX_INPUT + 1] = "\0";
		std::string password = "";

		int letterCountUsername = 0;
		int letterCountPassword = 0;

		void getUserName(char input[MAX_INPUT], int&letterCount);
		void getPass(char input[MAX_INPUT], int&letterCount);

		std::unordered_map<std::string, std::pair<bool, Rectangle>> inputFields;

		Rectangle submitButton;
		

};

