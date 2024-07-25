#pragma once

#ifndef TEACHER_H
#define TEACHER_H

#include"user.h"
#include"Assignment.h"
#include"class.h"
#include"Notification.h"

class Teacher : public User {	//inheritance

	string subjectTeacher;


public:
	Notification* n;
	Class* c;
	Assignment* assignment1;
	
	Teacher();
	Teacher(string);
	Teacher(string, string, string);
	void UploadAssignment();
	//void UploadMarks();
	void showdata();
	void showUploadedAssignment();
	void setData();
	//void classAvg();
	//void setGrade();
	void showMenu();
	~Teacher();
};

#endif