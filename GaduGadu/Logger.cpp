#include "Logger.h"



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

Logger::~Logger()
{
	mysql_close(connector);
}

void Logger::finish_with_error(MYSQL *con) {

	fprintf(stderr, "%s\n", mysql_error(con));
	exit(0);

}
