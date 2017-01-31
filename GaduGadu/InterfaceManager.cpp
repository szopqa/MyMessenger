#include "InterfaceManager.h"



InterfaceManager::InterfaceManager()
{
}


InterfaceManager::~InterfaceManager()
{
}

void InterfaceManager::showLoginMenu(char*log, char*pass) {
	
	system("cls");

	cout << "Insert login: ";
	cin >> log;
	cout << "Insert password: ";
	cin >> pass;

}


void InterfaceManager::showMainMenu() {

	int login_choice = 0;
	int login_result = 0;
	bool logged = false;
	AppLogic feature;
		

	cout << "1. Log in" << endl;
	cout << "2. Create a new account" << endl;
	cout << "3. Exit" << endl;
	cout << "==========================\n Choice: ";
	cin >> login_choice;



	while (logged == false) {


		switch (login_choice) {



			case 1:
			
				login_result = feature.Authorise();
				
				if (login_result == 1) {
					logged = true;
				}

			break;



				case 2:



					break;




					case 3:

						break;

							default:

								break;
		}



	}



}