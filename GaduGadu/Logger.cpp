#include "Logger.h"

using namespace std;

Logger::Logger(char * host, char * user, char * password, char * database)  //initialization
{

	this->loggedIn = false;

//DATABASE CONNECTION

	connector = mysql_init(NULL);

	if (connector == NULL) {
		fprintf(stderr, "mysql_init() failed\n");
		exit(0);
	}

	if (mysql_real_connect(connector, host, user, password, database, 0, NULL, 0) == NULL) {
		finish_with_error(connector);
	}
}



Logger::~Logger()
{
	mysql_close(connector);
}




int Logger::CreateNewAccount()
{

/*
	At first I have to check if nickname and email adress are not used yet.
	If they are free to use I can create a new account using login, password and email typed by user
*/


	char queryBuff[2048];
	bool userExists = false;

	char  loginTyped [50];
	char  passwordTyped [50];
	char  emailTyped [50];

#pragma region UserInterface

	system("cls");
	cout << "Insert login: \n";	cin >> loginTyped;
	cout << "Insert password: \n";	cin >> passwordTyped;
	cout << "Insert your email adress: \n";	cin >> emailTyped;

#pragma endregion


#pragma region PossibleOptionsWhileCreatingNewAccount

//FIRST : Checking if username is available

	sprintf_s(queryBuff, "SELECT user_id FROM users\
										WHERE login = '%s'", loginTyped);

	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);

	if (row != NULL) {
		userExists = true;
		return 1;					//username not available
		//TODO: return 1 while username is not available
	}






//SECOND : Checking if email adress is available

	sprintf_s(queryBuff, "SELECT user_id FROM users\
										WHERE email = '%s'", emailTyped);

	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);

	if (row != NULL) {
		userExists = true;
		return 2;
		//TODO : returns 2 when email adress is used
	}






//THIRD: Occurs when login and email are used

			/*

			sprintf_s(queryBuff, "SELECT user_id FROM users\
												WHERE login = '%s'\
												AND email = '%s'",login, email);

			result = getResult(queryBuff, connector);

			row = mysql_fetch_row(result);

			if (row != NULL) {
				userExists = true;
				return 3;
				//TODO : returns 3 when email login and adress are used
			}

			*/




//FOURTH : Everything is fine, lets create an account

	sprintf_s(queryBuff, "INSERT INTO users VALUE (user_id,'%s','%s','%s')",loginTyped, passwordTyped, emailTyped);

	if (mysql_query(connector, queryBuff)) {
		finish_with_error(connector);
	}

	/*
	result = mysql_store_result(connector);

	if (result == NULL) {
		finish_with_error(connector);
	}

	*/


	return 4;
	//TODO : Account successfully created


#pragma endregion


}



int Logger::Authorise()
{

	char queryBuff[2048];
	char  loginTyped[50];
	char  passwordTyped[50];



	system("cls");
	cout << "Insert login: \n";	cin >> loginTyped;
	cout << "Insert password: \n";	cin >> passwordTyped;




	sprintf_s(queryBuff, "SELECT user_id FROM users \
										 WHERE login = '%s' \
											AND password = '%s'",loginTyped, passwordTyped);


	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);


	if (row == NULL) {		//didnt find user in database - login failed

		loggedIn = false;
		return 0;

	}

	else {					//user found, looged in

		this->loggedIn = true;
		return 1;

	}


}


void Logger::finish_with_error(MYSQL *con) {

	fprintf(stderr, "%s\n", mysql_error(con));
	exit(0);

}




MYSQL_RES * Logger::getResult(char * buff, MYSQL * con){

	if (mysql_query(con, buff)) {
		finish_with_error(con);
	}

	MYSQL_RES *tempResult = mysql_store_result(con);

	if (tempResult == NULL) {
		finish_with_error(con);
		return nullptr;
	}

	return tempResult;

}



bool Logger::checkIfLoggedIn()
{
	if (this->loggedIn == true) {
		return true;
	}

	else
		return false;
}
