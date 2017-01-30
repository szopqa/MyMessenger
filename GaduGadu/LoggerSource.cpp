#include "Logger.h"

using namespace std;



void loginMenu(Logger &obj); 




int main() {

	Logger log("localhost", "root", "aX#>:&^443@dR", "gg");

//LOGIN MENU

	loginMenu(log);   




	system("pause");

	return 0;
}





void loginMenu(Logger &log) {

	int loginChoice = 0;
	int loginResult = 0;


//LOGGING IN LOOP - breaks only when loggin and password are correct

	while (log.checkIfLoggedIn() == false) {

		cout << "1. Log in" << endl;
		cout << "2. Create a new account" << endl;
		cout << "3. Exit" << endl;
		cout << "==========================\n Choice: ";
		cin >> loginChoice;

	switch (loginChoice) {

		case 1:

			loginResult = log.Authorise();

			switch (loginResult) {

			case 1:				//logged successfully

				system("cls");

				cout << "You have successfully logged in\n";

				break;


			default:			//unable to log in

				system("cls");

				cout << "Wrong login or password! Try again\n\n";


				break;
			}

			break;

		case 2:

			loginResult = log.CreateNewAccount();

			switch (loginResult) {

			case 1:

				system("cls");

				cout << "\nUser name is in use. Chose another one!\n\n";

				break;

			case 2:

				system("cls");

				cout << "\nEmail adress was used. Check your email for details\n\n";

				break;

				//TODO: case 3: break;

			case 4:

				system("cls");

				cout << "Account successfully created. You can now log in!";

				for (size_t i = 0; i < 6; i++)
				{
					Sleep(300);
					cout << ".";
				}

				cout << "\n\n";

				//TODO: email Authorisation

				break;

			default:
				break;

			}

			break;

		case 3:

			exit(0);

			break;

		default:

			cout << "Wrong choice" << endl;

			for (size_t i = 0; i < 6; i++)
			{
				Sleep(300);
				cout << ".";
			}

			//ERROR : infinite loop while pressing for egzample 'd'

			system("cls");

			break;

		}

	}



}