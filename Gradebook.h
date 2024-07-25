#pragma once

#ifndef GRADEBOOK_H
#define GRADEBOOK_H


#include<iostream>
using namespace std;
#include<string>
class Gradebook
{

    string grade;
    double classaverage;

public:
    Gradebook();
    void setGrade();
    void calculateclassavg();
    void classAvg();
    double getclassavg();
    string getgrade();

};
#endif