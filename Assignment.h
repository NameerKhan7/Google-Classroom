#pragma once

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
#include<sstream>
#include<fstream>
#include"Submission.h"
#include"Notification.h"
using namespace std;


class Assignment
{
    Notification* notification;
    string title;
    string description;
    int deadline[4] = { 0 };
    int pointvalue;
    string attachment;
    Submission* sub;
    int duedate[4] = { 0 };

public:
    //static int AssignmentCount;
    Assignment();
    //static int getConstructorCount();
    Assignment(string, string, int);
    void setDetails();
    void getAssignment();
    void showDeadline();
    void setDeadline();
    void setTitle(string);
    void setDescription(string);
    void setpointvalue(int );
    string getDescription();
    string getTitle();
    int getPointvalue();
    int* getDeadline();
    bool checkpreviousdeadline(Assignment&);
    void AddnewAssignment(Assignment&);
    void UpdateAssignment(Assignment&);
    void DeleteAssignment(Assignment&);
    bool showAssignment();
    void sendAssignment();
    bool checkSubmission();
    bool checkDueDate();
    string Attachfile();
    void ReadDueDatesFromFile();
   


};

//int Assignment::AssignmentCount = 0; //static counter variable to count the number of assignment
#endif
