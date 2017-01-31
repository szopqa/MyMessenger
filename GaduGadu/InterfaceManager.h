#pragma once

#include "AppLogic.h"

#include <iostream>
#include <string>

using namespace std;


class InterfaceManager
{
public:

	static void showMainMenu();
	static void showLoginMenu(char * log, char * pass);

	InterfaceManager();
	~InterfaceManager();
};

