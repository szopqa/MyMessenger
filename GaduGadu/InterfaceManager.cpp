#include "InterfaceManager.h"



InterfaceManager::InterfaceManager()
{
}


InterfaceManager::~InterfaceManager()
{
}


void InterfaceManager::showMainMenu(int &menu_choice) {

	cout << "1. Log in" << endl;
	cout << "2. Create a new account" << endl;
	cout << "3. Exit" << endl;
	cout << "==========================\n Choice: ";
	cin >> menu_choice;

}



void InterfaceManager::showLoginMenu(char*log, char*pass) {

	system("cls");

	cout << "Insert login: ";
	cin >> log;
	cout << "Insert password: ";
	cin >> pass;

}


void InterfaceManager::showCreateNewAccountMenu(char *log, char*pass, char*email) {

	system("cls");

	cout << "Insert login: \n";
	cin >> log;
	cout << "Insert password: \n";	
	cin >> pass;
	cout << "Insert your email adress: \n";
	cin >> email;

}