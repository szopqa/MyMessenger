#pragma once
#define HAVE_STRUCT_TIMESPEC
#include <iostream>
#include <my_global.h>
#include <mysql.h>

class Logger
{
private:
	MYSQL *connector;
	MYSQL_RES *result;
	MYSQL_ROW row;

	void finish_with_error(MYSQL *con);

public:
	Logger(char *host,char *user, char *password, char *database);
	int CreateNewAccount(char *login, char *password, char *email);
	int Authorise(char *login, char *password);
	~Logger();
};

