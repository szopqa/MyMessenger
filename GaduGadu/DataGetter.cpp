#include "DataGetter.h"

DataGetter::~DataGetter(){

}
	

DataGetter::DataGetter() {

}

DataGetter::DataGetter(char * host, char * user, char * password, char * database)
{

}



void DataGetter::finish_with_error(MYSQL *con) {

	fprintf(stderr, "%s\n", mysql_error(con));
	exit(0);

}



int DataGetter::findUsernameInDatabase(char * login_typed, char * password_typed)
{

	sprintf_s(this->queryBuff, "SELECT user_id FROM users \
										 WHERE login = '%s' \
											AND password = '%s'", login_typed, password_typed);

	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);

	if (row == NULL) {		//failed to logg in
		return 0;
	}

	else {
		return 1;
	}


}

bool DataGetter::checkIfUsernameIsAvailable(char * login_typed) {

	sprintf_s(queryBuff, "SELECT user_id FROM users\
										WHERE login = '%s'", login_typed);

	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);

	if (row != NULL) {		//username already exists in database
		return false;
	}

	else {
		return true;
	}

}

bool DataGetter::checkIfEmailAdressIsAvailable(char * email_typed)
{


	sprintf_s(queryBuff, "SELECT user_id FROM users\
										WHERE email = '%s'", email_typed);

	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);

	if (row != NULL) {			//email adress is in use
		return false;	
	}

	else {
		return true;
	}


}


MYSQL_RES * DataGetter::getResult(char * buff, MYSQL * con){
	
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

