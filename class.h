

#ifndef CLASS_H
#define CLASS_H
#include<string>
#include<iostream>
#include"Student.h"
using namespace std;


class Class {

	string className;
	string subjectName;
	string classDescription;
	
	// Student roster[50]; //limit of student in class
	Student *student;
	Class* c;
	

public:

	Class();
	Class(string, string, string);
	void setClassName(string);
	string getClassName();
	void setSubjectName(string);
	string getSubjectName();
	void setClassDescription(string);
	string getClassDescription();
	void AddTeacher();
	void AddStudent();
	void RemoveStudent(int );
	void viewclassdata();
	void createClass();
	void removeClass();
	void updateClass(Class &);
	void setData();
	


};




#endif