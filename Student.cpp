#include "student.h"


Student::Student()
{
    cout << "enter the roll no of the student " << endl;
    
    cin >> this->rollno;
    //cout << "Student default constructor" << endl;
}

Student::Student(string rn)
{
    this->rollno = rn;
}

Student::Student(string rn, string n, string email)
{
    this->rollno = rn;
    User(n, email);
}

void Student::showData()
{
    ShowDetails();
    cout << "Student's Roll no: " << this->rollno << endl;
}

void Student::setData()
{
    SetData();
    cout << "Enter student's Roll no: ";
    cin>>this->rollno;
}

void Student::Submission()
{
    submission->SumbitAssignment();
}

void Student::ViewGrades()
{
    // need grade class
}

void Student::viewMarks()
{
    cout << submission->getMarks();
}

void Student::showMenu()
{

    int choice = 0;
    int loop = 1;

    do
    {
        cout << endl;
        cout << "1.Show Data" << endl;
        cout << "2.set Students Data" << endl;
        cout << "3.Submission Data" << endl;
        cout << "4.View Grades" << endl;
        cout << "5.View Assignment" << endl;
        cout << "6.Submit Assignment " << endl;
        cout << "7.View Marks " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            this->showData();
            break;
        case 2:
            this->setData();
            break;
        case 3:
            this->Submission();
            break;
        case 4:
            this->ViewGrades();
            break;
        case 5:
            assignment->showAssignment();
            break;
        case 6:
        {
            //submission->ReadAnswer();
                submission->SumbitAssignment();        
            break;
        }
        case 7:
        {
            viewMarks();
            break;
        }
        case 0:
            loop = 0;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (loop != 0);
}

Student::~Student()
{
    delete submission;
    delete assignment;
}