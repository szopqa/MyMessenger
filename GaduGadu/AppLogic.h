#pragma once

#include "DataGetter.h"
#include "InterfaceManager.h"
#include "UserData.h"

#include <iostream>
#include <string>

using namespace std;

class AppLogic
{

private:
	DataGetter data;

public:

	AppLogic();
	~AppLogic();

	void initnializeMainMenu();

	int createNewAccount();
	int checIfUserExists(char * login, char * email);
	int Authorise();
};

