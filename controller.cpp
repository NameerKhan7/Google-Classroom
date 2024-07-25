#include "user.h"
#include"Teacher.h"
#include"Student.h"

int main()
{


        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // yellow font
    
        cout << "  ***    ****  ****  " << endl;
        cout << " *   *  *      *   * " << endl;
        cout << " *  **  *      ****  " << endl;
        cout << " *   *  *      *  *  " << endl;
        cout << "  ***    ****  *   * " << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // yellow font


    User* user;
   
    string role;
    cout << "Enter Role (student or teacher):" << endl;
    cin >> role;
    

    
    
        if (role == "student" || role == "Student")
        {
            
            Student s;
            user = &s;
            user->CreateAccount();           
            s.SetData();
            cout << endl;
            s.showMenu();
           
            
        }
        if (role == "Teacher" || role == "teacher")
        {

            Teacher t1;
            user = &t1;
            user->CreateAccount();          
            user->SetData();
            cout << endl;
            t1.showMenu();
            
        }
        

   
    

    



}