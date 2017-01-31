#include "UserData.h"

UserData::UserData(char * user_login, char*user_password)
{
	this->nickname = user_login;
	this->password = user_password;
	this->loggedIn = true;
}


UserData::~UserData()
{
}


string UserData::getUserNickname() {
	
	return nickname;

}

bool UserData::checkIfLoggedIn()
{
	return this->loggedIn;
}
