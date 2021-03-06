#pragma once

#define HAVE_STRUCT_TIMESPEC

#include <iostream>
#include <string>
#include <my_global.h>
#include <mysql.h>

class Logger
{
private:

	MYSQL *connector;
	MYSQL_RES *result;
	MYSQL_ROW row;

	bool loggedIn;
	char * login;
	char * password;
	char * email;

	void finish_with_error(MYSQL *con);

public:
	Logger(char *host,char *user, char *password, char *database);
	~Logger();
	int createNewAccount();
	int Authorise();
	MYSQL_RES * getResult(char *buff, MYSQL *con);
	bool checkIfLoggedIn();
};
