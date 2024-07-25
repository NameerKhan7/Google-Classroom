#include "assignment.h"


Assignment::Assignment()
{
    cout << "Default Assignment constructor" << endl;
    //AssignmentCount++;
    //cout << AssignmentCount << endl;
    this->setDetails();
}

Assignment::Assignment(string title, string desc, int points)
{
    this->title = title;
    this->description = desc;
    this->pointvalue = points;
    this->setDeadline();
    //AssignmentCount++;
}

void Assignment::setDetails()
{
    string str;
    cout << "Enter title: ";
    cin >> this->title;
    cout << "Description: ";
    cin >> description;
    cout << "Points: ";
    cin >> this->pointvalue;
    this->setDeadline();
}



string Assignment::Attachfile() {
    fstream file("assignmentquestion.txt");

    if (!file)
    {
        cout << "Error opening file: "  << endl;
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string fileData = buffer.str();

    return fileData;
}


bool Assignment::checkSubmission()
{
    ifstream inputFile("Submission.txt");

    if (!inputFile)
    {
        cout << "Error opening the file." <<endl;
        return false;
    }

    if (inputFile.peek() == ifstream::traits_type::eof())
    {
        // File is empty
        inputFile.close();
        return false;
    }
    else
    {
        // File is not empty, read and print the data
        string data;
        data.assign((istreambuf_iterator<char>(inputFile)),
            (istreambuf_iterator<char>()));
        inputFile.close();
        cout << "Data in the file:\n" << data << endl;
        return true;
    }
    
}

void Assignment::sendAssignment()
{
    attachment = Attachfile();
    
    ofstream ofile("Assignment.txt");

    if (!ofile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    // Get the assignment details using the getAssignment function
    stringstream ss;
    ss << "Marks: " << this->pointvalue << "\t\t\t\t"
        << "Assignment: " << this->title << "\t\t\t\t"
        << "Date: " << this->deadline[0] << "," << this->deadline[1] << " time: " << this->deadline[2] << ":" << this->deadline[3] << endl
        << "Description: " << this->description << endl
        << "Question " << this->attachment << endl;
    // Write the assignment details to the file
    ofile << ss.str() << endl;

    // Close the file
    ofile.close();
}




bool Assignment::showAssignment()
{
    ifstream ifile("Assignment.txt" , ios::app);

    if (!ifile)
    {
        cout << "Error opening file!" << endl;
        return 0;
    }

    string line;
    while (getline(ifile, line))
    {
        
        cout << line << endl;
    }

    

    ifile.close();
    return 1;
}



void Assignment::ReadDueDatesFromFile() {
    ifstream inFile("DueDates.txt");

    
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int date, month, hour, minute;
    char comma; // To read the comma separator between date, month, hour, and minute

    if (inFile >> date >> comma >> month >> comma >> hour >> comma >> minute) {
        duedate[0] = date;
        duedate[1] = month;
        duedate[2] = hour;
        duedate[3] = minute;
    }
    else {
       cout << "Invalid data in the file!" << endl;
    }

    inFile.close();
}

bool Assignment :: checkDueDate() {

    if (deadline[1] > duedate[1]) // deadline[1] is month
    {
        return 1;
    }

    if (deadline[1] == duedate[1]) // deadline[1] is month
    {
        if (deadline[0] > duedate[0]) // deadline[0] is date
        {
            return 1;
        }
        else if (deadline[0] ==  duedate[0])
        {
            if (deadline[3] > duedate[3])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
            return 0;
    }

    return 0;
}

void Assignment::setDeadline()
{
    int tempdate = 0;
    int tempmonth = 0;
    int temphour = 0;
    int tempmin = 0;
    cout << "Enter deadline ";
    cout << "Enter date (in digits): ";
    cin >> tempdate;
    if (tempdate >= 1 && tempdate <= 31)
        this->deadline[0] = tempdate;
    else
    {
        throw runtime_error("Invalid input date");
    }

    cout << "Enter month (in digits): ";
    cin >> tempmonth;
    if (tempmonth >= 1 && tempmonth <= 12)
    {
        this->deadline[1] = tempmonth;
    }
    else
        throw runtime_error("Invalid input month");

    cout << "Enter hour (in digits from 0 - 24): ";
    cin >> temphour;
    if (temphour >= 0 && temphour <= 24)
        this->deadline[2] = temphour;
    else
        throw runtime_error("Invalid input hour");

    cout << "Enter minute (in digits from 0 - 60): ";
    cin >> tempmin;
    if (tempmin >= 0 && tempmin <= 60)
    {
        this->deadline[3] = tempmin;
    }
    else
        throw runtime_error("invalid input minutes");
}

void Assignment::getAssignment()
{
    cout << "Marks " << pointvalue << "\t\t\t\t"
        << "Assignment: " << this->title << "\t\t\t\t"
        << "Date:" << this->deadline[0] << "," << this->deadline[1] << " time:" << this->deadline[2] << ":" << this->deadline[3] << endl;
    cout << "Description:" << this->description << endl;
    cout <<"Question \n"<< attachment << endl;

}

void Assignment::setTitle(string title)
{
    this->title = title;
}

void Assignment::setDescription(string description)
{
    this->description = description;
}

void Assignment::setpointvalue(int value)
{
    this->pointvalue = value;
}

string Assignment::getTitle()
{
    return this->title;
}

string Assignment::getDescription()
{
    return this->description;
}

int Assignment::getPointvalue()
{
    return this->pointvalue;
}

int* Assignment::getDeadline()
{
    return this->deadline;
}

void Assignment::showDeadline() // function checks if this->object deadline is not before the previous assignment deadline
{
    cout << "Date: " << this->deadline[0] << " Month: " << this->deadline[1] << " Time " << this->deadline[2] << ":" << deadline[3] << endl;
}

bool Assignment::checkpreviousdeadline(Assignment& previousAssignment)
{
    if (this->deadline[1] > previousAssignment.deadline[1]) // deadline[1] is month
    {
        return 1;
    }

    if (this->deadline[1] == previousAssignment.deadline[1]) // deadline[1] is month
    {
        if (this->deadline[0] > previousAssignment.deadline[0]) // deadline[0] is date
        {
            return 1;
        }
        else if (this->deadline[0] == previousAssignment.deadline[0])
        {
            if (this->deadline[3] > previousAssignment.deadline[3])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
            return 0;
    }

    return 0;
}

void Assignment::AddnewAssignment(Assignment& obj)
{
    // this->setDetails();
    Assignment temp;
    
    
    int choice = 0;
    cout << "is there any previous assignments? 1 for yes 0 for no" << endl;
    cin >> choice;
    int prev = 0;
    if (choice == 1)
    {

        // add the object of the previous assignment
        prev = temp.checkpreviousdeadline(obj);
        if (prev == 0)
        {

            cout << "You cannot add a new assignment before the previous assignment duedate" << endl;
            this->DeleteAssignment(temp);

        }
        else
        {
            notification = new Notification;
            cout << "new assignment added" << endl;
        }
    }
    else if (choice == 0)
    {

        cout << "New assignment is added" << endl;
    }
    else
        cout << "invalid input" << endl;
        //throw runtime_error("Invalid input");
}

void Assignment::UpdateAssignment(Assignment &obj)
{
    cout << "Enter Updated version" << endl;
    Assignment temp;
    
    obj.title = temp.title;
    obj.description = temp.description;
    obj.pointvalue = temp.pointvalue;
    for (int i = 0; i < 4; i++)
    {
        obj.deadline[i] = temp.deadline[i];
    }

    cout << "Your assignment has been updated" << endl;
}

void Assignment::DeleteAssignment(Assignment& obj)
{
    obj.title = "";
    obj.description = "";
    obj.pointvalue = 0;
    for (int i = 0; i < 4; i++)
    {
        obj.deadline[i] = 0;
    }

    cout << "Assignment has been removed" << endl;
}


