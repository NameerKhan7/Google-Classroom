#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include"Assignment.h"
#include"user.h"
#include"submission.h"
using namespace std;

class Student : public User {

	string rollno;
	Assignment* assignment;
	Submission * submission;


public:
	Student();
	Student(string);
	Student(string, string, string);
	void showData();
	void setData();
	void Submission();
	void ViewGrades();
	void viewMarks();	
	void showMenu();

	~Student();



};

#endif // Student_H