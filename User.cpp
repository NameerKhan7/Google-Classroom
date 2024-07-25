#include "user.h"
#include"Teacher.h"

User::User(string name , string role )
{
    this->Name = name;
    this->Role = role;
}

void User::SetData()
{

    cout << "Inputting data..." << endl;
    cout << "Enter Name:" << endl;
    cin >> this->Name;
    cout << "Enter Email:" << endl;
    cin >> this->Email;

    
}

bool User::CreateAccount()
{

    cout << "HI!" << endl;
    cout << "You have created a new account first." << endl;
    bool pass = false, Id = false;
    Id = this->setID();
    pass = this->setPassword();
    if (pass && Id)
    {
        
        
        //this->SetData();
        return true;
    }
    else
    {
        return false;
    }
}

void User::ShowDetails()
{
    cout << "User Details" << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Email: " << this->getEmail() << endl;
    // cout << "Role: " << this->getRole() << endl;
}

bool User::login()
{
    // int retry = 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
    cout << "LOGIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
    bool Pass = 0, Id = 0;
    Id = this->CheckID();
    Pass = this->CheckPassword();
    // string tempID = this->DecryptID();
    // string tempPass = this->DecryptPassword();
    if (Pass == 0)
    {
        cout << "Incorrect password" << endl;
        return 0;
    }

    if (Id == 0)
    {
        cout << "Incorrect id" << endl;
        return 0;
    }

    return 1;
}

bool User::setID()
{
    cout << "Enter a unique ID(with space)" << endl;
    cin >> UniqueID;
    Idlen = UniqueID.size();
    this->EncryptID();
    if (Idlen == 0 || UniqueID == "")
    {
        return false;
    }

    return true;
}

bool User::setPassword()
{
    cout << "Enter a password" << endl;
    cin >> Password;
    Passlen = Password.size();
    this->EncryptPassword();

    if (Password == "" || Passlen == 0)
    {
        return false;
    }

    return true;
}

bool User::CheckID()
{
    string Id;
    cout << "Enter ID: ";
    cin >> Id;
    
    int tempLen = Id.size();
    string fromfile;
    
    fromfile = this->DecryptID();
    // cout<<fromfile<<"----ID"<<endl;
    int flen = fromfile.length();
    // cout << fromfile << endl;
    //  cout<<fromfile.size()<<" fromfile length: "<<endl;
    // cout<<tempLen<<"Runn time "<<endl;

    if (flen == tempLen)
    {
        for (int i = 0; i < Idlen; i++)
        {
            if (Id[i] != fromfile[i])
            {
                cout << "Unique Id did'nt Match" << endl;
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

bool User::CheckPassword()
{
    string password;

    cout << "Enter Password: ";
    cin >> password;
    
    int templen = password.size();
    
    string fromfile = this->DecryptPassword();
    // cout<<fromfile<<"----Password"<<endl;
    // cout<<fromfile.size()<<" fromfile length: "<<endl;
    // cout<<templen<<"Runn time "<<endl;
    int flen = fromfile.length();

    if (templen == flen)
    {
        for (int i = 0; i < Passlen; i++)
        {
            if (password[i] != fromfile[i])
            {
                cout << "Password did'nt Match" << endl;
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

void User::setName(string name)
{

    this->Name = name;
}

void User::setEmail(string email)
{
    this->Email = email;
}

void User::setRole(string role)
{
    this->Role = role;
}

string User::getName()
{
    return this->Name;
}

string User::getEmail()
{
    return this->Email;
}

string User::getRole()
{
    return this->Role;
}
void User::EncryptID()
{
    ofstream ofile;
    ofile.open("ID.txt");

    if (!ofile)
    {
        cout << "Error opening file." << endl;
        return;
    }

    // Write the UniqueID as binary data
    ofile << UniqueID;
   // ofile << "\n"; // Add a new line to separate ID and Password

    ofile.close();
}

void User::EncryptPassword()
{
    ofstream ofile;
    ofile.open("Password.txt"); // Open the file in append mode

    if (!ofile)
    {
        cout << "Error opening file." << endl;
        return;
    }

    // Write the Password as binary data
    ofile<<Password;
    

    ofile.close();
}

string User::DecryptID()
{   
    string ID;
    ifstream ifile("ID.txt");

    if (!ifile) {
        cout << "Error opening file." << endl;
        return "";
    }

    // Read the data from the file and store it in a stringstream
    stringstream ss;
    ss << ifile.rdbuf();

    // Convert the stringstream to a string to retrieve the decrypted data
    ID = ss.str();

    ifile.close();
    return ID;
}

string User::DecryptPassword()
{
    string Pass;
    ifstream ifile("ID.txt");

    if (!ifile) {
       cout << "Error opening file." << endl;
        return "";
    }

    // Read the data from the file and store it in a stringstream
    stringstream ss;
    ss << ifile.rdbuf();

    // Convert the stringstream to a string to retrieve the decrypted data
    Pass = ss.str();

    ifile.close();

    return Pass;
}

// void User:: Teacherobj()
// {
//     teacher = new Teacher;

//     teacher->showMenu();


// }

// void User::Studentobj()
// {
//     student = new Student;

//     student->showMenu();
// }

