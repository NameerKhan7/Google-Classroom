
#include"class.h"




Class::Class()
{
    void setData();
}

Class::Class(string cn, string sn, string desc)
{
    this->className = cn;
    this->subjectName = sn;
    this->classDescription = desc;

}

void Class::setData()
{
    cout << "enter className : " << endl;
    cin >> this->className;
    cout << "enter subjectName : " << endl;
    cin >> this->subjectName;
    cout << "enter Description : " << endl;
    cin >> this->classDescription;
}

void Class::setClassName(string cName)
{
    this->className = cName;
}

void Class::setSubjectName(string sName)
{
    this->subjectName = sName;
}

void Class::setClassDescription(string sDescription)
{
    this->classDescription = sDescription;
}

string Class::getClassName()
{
    return this->className;
}

string Class::getSubjectName()
{
    return this->subjectName;
}

string Class::getClassDescription()
{
    return this->classDescription;
}

void Class::AddStudent()
{
    
        student = new Student;
        
}


void Class::RemoveStudent(int)
{
    delete student;
}

void Class::viewclassdata()
{
    cout << "ClassName : "<<className << endl;
    cout << "SubjectName :" << subjectName << endl;
    cout << "Description : " << classDescription << endl;
}

void Class::createClass()
{
     c = new Class;
}

void Class::removeClass()
{
    delete c;
}

void Class::updateClass(Class &obj)
{
    obj.setData();
}

