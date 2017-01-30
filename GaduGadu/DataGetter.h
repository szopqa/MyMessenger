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

	~DataGetter();

};

