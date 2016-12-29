#include "Logger.h"

using namespace std;

int main() {

	int loginChoice = 0;
	int createRes = 0;

	
	Logger log("localhost", "root", "aX#>:&^443@dR", "gg");


//LOGGING IN LOOP

	while (log.checkIfLoggedIn() == false) {

		cout << "1. Log in" << endl;
		cout << "2. Create a new account" << endl;
		cout << "3. Exit" << endl;
		cout << "==========================\n Choice: ";
		cin >> loginChoice;

		switch (loginChoice) {

		case 1:
			//TODO : Authorise
			break;

		case 2:
			
			createRes = log.CreateNewAccount();
				
					switch (createRes) {
						
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

						cout << "Account successfully created. You can no log in!";

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
			break;

		default:
			break;

		}

	}

	system("pause");

	return 0;
}