#include "InterfaceManager.h"



InterfaceManager::InterfaceManager()
{
}


InterfaceManager::~InterfaceManager()
{
}


void InterfaceManager::ShowMainMenu() {

	int loginChoice = 0;
	int loginResult = 0;
	AppLogic action;

	cout << "1. Log in" << endl;
	cout << "2. Create a new account" << endl;
	cout << "3. Exit" << endl;
	cout << "==========================\n Choice: ";
	cin >> loginChoice;

	switch (loginChoice) {

		case 1:
			
			action.Authorise();

			break;



		case 2:

			break;

		case 3:

			break;

		default:

			break;
	}

}