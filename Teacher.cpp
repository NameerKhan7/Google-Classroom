

#include "teacher.h"

Teacher::Teacher()
{
    //cout << "Teacher Default constructor." << endl;
}

Teacher::Teacher(string course)
{
    this->subjectTeacher = course;
}

Teacher::Teacher(string course, string name, string email)
{
    this->subjectTeacher = course;
    User(name, email);
}

void Teacher::showdata()
{
    ShowDetails();
    cout << "Course: " << this->subjectTeacher;
}

void Teacher::setData() 
{
    SetData();
    cout << "Enter course name :";
    cin >> this->subjectTeacher;
}
void Teacher::UploadAssignment()
{
     assignment1 = new Assignment();
     cout << endl;
     n = new Notification;
}

void Teacher::showUploadedAssignment()
{
    
    this->assignment1->getAssignment();
}
void Teacher::showMenu()
{
    int choice = 0;
    int loop = 1;

    do
    {
        cout << endl;
        cout << "Teacher's Menu" << endl;
        cout << "1.Upload Assignment" << endl;
        cout << "2._____*BLANK*__________" << endl;
        cout << "3.Set Teacher's Data" << endl;
        cout << "4.Class average" << endl;
        cout << "5.Set Grade" << endl;
        cout << "6.show Data" << endl;
        cout << "7.View Uploaded Assignment" << endl;
        cout << "8.Update Assignment " << endl;
        cout << "9.Add New assignment" << endl;
        cout << "10.Remove Assignment" << endl;
        cout << "11.Check Submission " << endl;
        cout << "0. to exit" << endl;
        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            this->UploadAssignment();
            this->assignment1->sendAssignment();
            break;
        case 2:
            
            break;
        case 3:
            this->setData();
            break;
        case 4:
        //    this->classAvg();
            break;
        case 5:
       //     this->setGrade();
            break;
        case 6:
            this->showdata();
            break;
        case 7:
            this->showUploadedAssignment();
            break;
        case 8:
            this->assignment1->UpdateAssignment(*assignment1);
            break;
        case 9:
            this->assignment1->AddnewAssignment(*assignment1);
            break;
        case 10:
            this->assignment1->DeleteAssignment(*assignment1);
            break;
        case 11:
        {   bool check = 0;
            check = this->assignment1->checkSubmission();
            if (check == true)
            {
                cout << "Student submitted " << endl;
            }
            else
            {
                cout << "Student did'nt Submitted yet" << endl;
                
            }
            break;
        }
        case 0:
            loop = 0;
            break;
        default:
            cout << "invalid input" << endl;
            break;
        }

    } while (loop != 0);
}

Teacher::~Teacher()
{
     delete assignment1;
}
