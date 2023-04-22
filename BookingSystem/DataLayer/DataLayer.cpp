#include "pch.h"
#include "DataLayer.hpp"


DataLayer::DataLayer()
{
}

DataLayer::~DataLayer()
{
}

void DataLayer::connect()
{
	nanodbc::connection conn(NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=localhost\\SQLEXPRESS;Database=test;Trusted_Connection=yes;"));
	std::cout << conn.connected() << " HERE we are" << std::endl;
}
