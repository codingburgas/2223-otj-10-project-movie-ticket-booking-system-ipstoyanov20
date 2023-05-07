#include "pch.h"
#include "DataLayer.hpp"

//void User::insert(int id, const std::string& name, int age, const std::string& email)
//{
//    // Define the SQL statement
//    std::string sql = "INSERT INTO users (id, name, age, email) VALUES (?, ?, ?, ?)";
//
//    // Prepare the SQL statement
//    nanodbc::statement stmt(conn_);
//    stmt.prepare(sql);
//
//    // Bind the parameters to the statement
//    stmt.bind(0, &id);
//    stmt.bind(1, name.c_str());
//    stmt.bind(2, &age);
//    stmt.bind(3, email.c_str());
//
//    // Execute the statement
//    stmt.execute();
//}
//
//void User::update(int id, const std::string& name, int age, const std::string& email)
//{
//    // Define the SQL statement
//    std::string sql = "UPDATE users SET name = ?, age = ?, email = ? WHERE id = ?";
//
//    // Prepare the SQL statement
//    nanodbc::statement stmt(conn_);
//    stmt.prepare(sql);
//
//    // Bind the parameters to the statement
//    stmt.bind(0, name.c_str());
//    stmt.bind(1, &age);
//    stmt.bind(2, email.c_str());
//    stmt.bind(3, &id);
//
//    // Execute the statement
//    stmt.execute();
//}
//void User::remove(int id)
//{
//    // Define the SQL statement
//    std::string sql = "DELETE FROM users WHERE id = ?";
//
//    // Prepare the SQL statement
//    nanodbc::statement stmt(conn_);
//    stmt.prepare(sql);
//
//    // Bind the parameter to the statement
//    stmt.bind(0, &id);
//
//    // Execute the statement
//    stmt.execute();
//}
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

}

void Data::select(int id)
{
        
        conn_.connect(NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=ticket-system.database.windows.net;Database=system;Uid=ipstoyanov20;Pwd={Qwer1234};Encrypt=yes;"));
        // Define the SQL statement
        // Define the SQL statement
        std::string sql = "SELECT * FROM [User] WHERE id = ?";

        // Prepare the SQL statement
        nanodbc::statement stmt(conn_);
        stmt.prepare(sql);

        // Bind the parameter to the statement
        stmt.bind(0, &id);

        // Execute the statement
        nanodbc::result results = stmt.execute();

        // Print the results
        if (results.next())
        {
                std::cout << "User: " << results.get<int>("id") << ", "
                << results.get<std::string>("email") << ", "
                << results.get<std::string>("password") << std::endl;
        }
        else
        {
            std::cerr << "User not found" << std::endl;
        }
        conn_.disconnect();
}
