#pragma once
class AppLogic
{

private:
	bool loggedIn;

public:

	AppLogic();
	~AppLogic();

	int CreateNewAccount();
	int Authorise();
	bool checkIfLoggedIn();	
};

