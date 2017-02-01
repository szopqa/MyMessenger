#include "AppLogic.h"


AppLogic::AppLogic(){

	DataGetter data("localhost", "root", "aX#>:&^443@dR", "gg");

}


AppLogic::~AppLogic()
{
}

void initializeMainMenu() {

	int login_choice;

	bool logged = false;

	InterfaceManager::showMainMenu(login_choice);

	while (logged == false) {

		switch (login_choice) {

		case 1:
			
			break;

		}
		

	}


}

int AppLogic::createNewAccount(){
	
	char login_typed[50];
	char password_typed[50];
	char mail_typed[50];

	int creatingResult = 0;

	InterfaceManager::showCreateNewAccountMenu(login_typed, password_typed, mail_typed);
	
	creatingResult = checIfUserExists(login_typed, mail_typed);

	switch (creatingResult) {
	
		case 1:

		break;

		default:
			//TODO
		break;
	}
	
}

int AppLogic::checIfUserExists(char *login, char*email) {

	bool usernameIsAvailable = false;
	bool emailIsAvailable = false;


	usernameIsAvailable = data.checkIfUsernameIsAvailable(login);
	emailIsAvailable = data.checkIfEmailAdressIsAvailable(email);

	if (usernameIsAvailable == true && emailIsAvailable == true) {
		return 1;
	}

	//TODO

		else if (usernameIsAvailable == true && emailIsAvailable == false) {
			//Email in use
		}

		else if (usernameIsAvailable == false && emailIsAvailable == true) {
			//username in use
		}

		else {
			//both email and username are in use
		}

}

int AppLogic::Authorise()
{

	char login_typed[50];
	char password_typed[50];

	InterfaceManager::showLoginMenu(login_typed, password_typed);		

	int loginResult = data.findUsernameInDatabase(login_typed, password_typed);
	// 0 failed, 1 logged in

	if (loginResult == 1) {
		UserData user(login_typed, password_typed);

		return 1;
	}

	else {
	
		return 0;

	}

}
