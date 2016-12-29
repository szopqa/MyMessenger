#include "Logger.h"

using namespace std;

Logger::Logger(char * host, char * user, char * password, char * database)  //initialization
{
	connector = mysql_init(NULL);

	if (connector == NULL) {
		fprintf(stderr, "mysql_init() failed\n");
		exit(0);
	}

	if (mysql_real_connect(connector, host, user, password, database, 0, NULL, 0) == NULL) {
		finish_with_error(connector);
	}
}

int Logger::CreateNewAccount(char * login, char * password, char *email)
{

/*
	At first I have to check if nickname and email adress are not used yet. 
	If they are free to use I can create a new account using login, password and email typed by user
*/


	char queryBuff[2048];
	bool userExists = false;




//FIRST : Checking if username is available 

	sprintf_s(queryBuff, "SELECT user_id FROM users\
										WHERE login = '%s'", login);

	if (mysql_query(connector, queryBuff)) {
		finish_with_error(connector);
	}

	result = mysql_store_result(connector);

	if (result == NULL) {
		finish_with_error(connector);
	}

	row = mysql_fetch_row(result);

	if (row != NULL) {
		userExists = true;
		return 1;					//username not available
		//TODO: return 1 while username is not available
	}






//SECOND : Checking if email adress is available

	sprintf_s(queryBuff, "SELECT user_id FROM users\
										WHERE email = '%s'", email);

	if (mysql_query(connector, queryBuff)) {
		finish_with_error(connector);
	}

	result = mysql_store_result(connector);

	if (result == NULL) {
		finish_with_error(connector);
	}

	row = mysql_fetch_row(result);

	if (row != NULL) {
		userExists = true;
		return 2;
		//TODO : returns 2 when email adress is used
	}






//THIRD : Everything is fine, lets create an account


	sprintf_s(queryBuff, "INSERT INTO users VALUE \(user_id,'%s','%s','%s')",login, password, email);

	if (mysql_query(connector, queryBuff)) {
		finish_with_error(connector);
	}

	result = mysql_store_result(connector);

	if (result == NULL) {
		finish_with_error(connector);
	}


	return 3;
	//TODO : Account successfully created
}


Logger::~Logger()
{
	mysql_close(connector);
}

void Logger::finish_with_error(MYSQL *con) {

	fprintf(stderr, "%s\n", mysql_error(con));
	exit(0);

}

int Logger::Authorise(char * login, char * password)
{
	
}
