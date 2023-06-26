#include "pch.h"
#include "DataLayer.hpp"

Data* Data::instance = nullptr;
Data* Data::getInstance()
{
    if (instance == nullptr)
    {
		instance = new Data();
	}
	return instance;
}

Data::Data()
{
    conn_.connect(NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=movie-app.database.windows.net;Database=app;Uid=ipstoyanov20;Pwd={Qwer1234};Encrypt=yes;"));
}

bool Data::select(std::string username, std::string password)
{
    std::cout << "SELECTING USER FROM DATABASE....";
        // Define the SQL statement
        // Define the SQL statement
        std::string sql = "SELECT * FROM [User] WHERE username = ? AND [password] = ?";

        // Prepare the SQL statement
        nanodbc::statement stmt(conn_);
        stmt.prepare(sql);

        // Bind the parameter to the statement
        stmt.bind(0, username.c_str());
        stmt.bind(1, password.c_str());

        // Execute the statement
        nanodbc::result results = stmt.execute();

        // Print the results
        if (results.next())
        {
                std::cout << "IN DATABASE THERE IS USER: "
                << results.get<std::string>("username") << ", PASSWORD:"
                << results.get<std::string>("password") << std::endl;
            return true;
        }
        else
        {
            std::cerr << "User not found" << std::endl;
            return false;
        }
        conn_.disconnect();
}
