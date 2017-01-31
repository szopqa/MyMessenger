#pragma once

#include <iostream>
#include <string>

using namespace std;

class UserData
{
private:
	string nickname;
	string password;
	bool loggedIn;

public:
	UserData();
	UserData(char * user_login, char * user_password);
	~UserData();

	string getUserNickname();
	bool checkIfLoggedIn();
};

