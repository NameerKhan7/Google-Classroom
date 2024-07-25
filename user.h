#pragma once

#ifndef USER_H
#define USER_H

#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <numeric>
#include <windows.h>
//#include"Teacher.h"
//#include"Teacher.h"
using namespace std;


class User
{

protected:
    string Name;
    string Email;
    string Role;
    string UniqueID = "";
    int Idlen = 0;
    string Password = "";
    int Passlen = 0;
    // Class UserClass;
public:
    // Student *student;
    
    User(string = "", string = ""); // -- default parameterized constructor for user
//    void Studentobj();
//    void Teacherobj();
    void virtual SetData();                 // -- setAll Data of the user
    void ShowDetails();             // -- show the details of the user
    void EncryptID();               // encrypt Id of the user
    void EncryptPassword();         // encrypt Password of the user
    string DecryptID();             // decrypt ID of the user
    string DecryptPassword();       // decrypt password of the user
    bool CheckPassword();           // check password
    bool CheckID();                 // check ID of the user
    bool setPassword();             // set the password
    bool setID();                   // set Unique ID of the user
    bool CreateAccount();           // -- create a new account
    bool login();                   // -- login
    void setName(string);
    string getName();
    void setEmail(string);
    string getEmail();
    void setRole(string);
    string getRole();
};

#endif