#pragma once
#include "pch.h"

class Data
{
public:

    //// Define a function to insert a user into the database
    //void insert(int id, const std::string& name, int age, const std::string& email);

    //// Define a function to update a user in the database

    //void update(int id, const std::string& name, int age, const std::string& email);

    //// Define a function to delete a user from the database
    //void remove(int id);

    // Define a function to select a user from the database
    bool select(std::string username, std::string password);
    ~Data();
    static Data* getInstance();
private:
    Data();
    nanodbc::connection conn_;
    static Data* instance;
};
