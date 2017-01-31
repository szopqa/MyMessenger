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



int DataGetter::findUsernameInDatabase(char * loginTyped, char * passwordTyped)
{
	
	
	char queryBuff[2048];

	sprintf_s(queryBuff, "SELECT user_id FROM users \
										 WHERE login = '%s' \
											AND password = '%s'", loginTyped, passwordTyped);

	result = getResult(queryBuff, connector);

	row = mysql_fetch_row(result);

	if (row == NULL) {		//failed to logg in
		return 0;
	}

	else {
		return 1;
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

