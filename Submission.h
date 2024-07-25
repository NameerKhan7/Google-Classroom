#pragma once

#ifndef SUBMISSION_H
#define SUBMISSION_H

#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Submission
{

    int duedate[4] = { 0 };
    string fileattachment;
    bool evaluatestatus;
    string Feedback;
    double marks;
    

   // void setMarks();

public:
    Submission();
    Submission(int&, bool, string);
    void SumbitAssignment();
    void setData();
    //void getGrades();
    void givefeedback();
    void evaluate();
    void setMarks( );
    void setAttachment(string);
    string getAttachment();
    void setFeedback(string);
    string getFeedback();
    double getMarks();
    void setDuedate();
    void viewMarks();
    void SumbitDueDate();
    int& getDueDate();

    string ReadAnswer();
};
#endif
