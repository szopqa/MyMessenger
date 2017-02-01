#pragma once

#include "AppLogic.h"

#include <iostream>
#include <string>

using namespace std;


class InterfaceManager
{
public:

	static void showMainMenu(int &menu_choice);
	static void showLoginMenu(char * log, char * pass);
	static void showCreateNewAccountMenu(char *log, char*pass, char*email);

	InterfaceManager();
	~InterfaceManager();
};

