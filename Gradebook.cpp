#include"gradebook.h"


Gradebook::Gradebook()
{
    cout << "Gradebook default constructor";

}

double Gradebook::getclassavg()
{
    return classaverage;
}

string Gradebook::getgrade()
{
    return grade;
}

void Gradebook::classAvg()
{
    int no_of_students = 0;
    cout << "Enter no. of students in class ";
    cin >> no_of_students;

    // classaverage = marks/no_of_students; //have to work where to get marks



}