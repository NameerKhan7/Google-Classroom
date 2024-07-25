
#include"Notification.h"

Notification::Notification()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
	cout << "NEW ASSIGNMENT HAS BEEN ADDED BY TEACHER" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // green font
}

