#pragma once
#include "pch.h"

class Data
{
public:

    // Define a function to select a user from the database
    bool select(std::string username, std::string password);
    ~Data();
    static Data* getInstance();
private:
    Data();
    nanodbc::connection conn_;
    static Data* instance;
};
