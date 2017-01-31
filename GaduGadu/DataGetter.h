#pragma once

#define HAVE_STRUCT_TIMESPEC

#include<iostream>
#include <string>
#include <my_global.h>
#include <mysql.h>


class DataGetter{

	MYSQL *connector;
	MYSQL_RES *result;
	MYSQL_ROW row;

public:
	
	DataGetter(char *host, char *user, char *password, char *database);
	DataGetter();
	~DataGetter();

	int findUsernameInDatabase(char *login, char*password);
	MYSQL_RES * getResult(char *buff, MYSQL *con);
	void finish_with_error(MYSQL *con);
};

