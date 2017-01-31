#include "AppLogic.h"


AppLogic::AppLogic(){

}


AppLogic::~AppLogic()
{
}

int AppLogic::CreateNewAccount()
{
	return 0;
}



int AppLogic::Authorise()
{

	char loginTyped[50];
	char passwordTyped[50];

	InterfaceManager::showLoginMenu(loginTyped, passwordTyped);		

	int loginResult = data.findUsernameInDatabase(loginTyped, passwordTyped);
	// 0 failed, 1 logged in

	if (loginResult == 1) {
		UserData user(loginTyped, passwordTyped);

		return 1;
	}

	else {
	
		return 0;

	}

}
