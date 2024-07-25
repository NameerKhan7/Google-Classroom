#include "submission.h"

Submission::Submission()
{

}

Submission::Submission(int& due, bool evaluate, string fb)
{
    *this->duedate = due;
    this->evaluatestatus = evaluate;
    this->Feedback = fb;
}

void Submission::setData()
{
    
    cout << "Enter you submission time and date" << endl;
    this->setDuedate();

}

void Submission::setDuedate()
{
    int tempdate = 0;
    int tempmonth = 0;
    int temphour = 0;
    int tempmin = 0;
    cout << "Enter deadline ";
    cout << "Enter date (in digits): ";
    cin >> duedate[0];
   

    cout << "Enter month (in digits): ";
    cin >> duedate[1];
    
    
      //  throw runtime_error("Invalid input month");

    cout << "Enter hour (in digits from 0 - 24): ";
    cin >> duedate[2];
    

    cout << "Enter minute (in digits from 0 - 60): ";
    cin >> duedate[3];
    
}


string Submission::ReadAnswer()
{
    string data;
    string filename = "answer.txt"; 

    fstream inputFile(filename);

    if (inputFile.is_open()) {
        // Read the entire content of the file into the string 'data'
        data.assign((istreambuf_iterator<char>(inputFile)),
            (istreambuf_iterator<char>()));

        inputFile.close();
        cout << endl <<data << endl;
        return data;
    }
    else {
        cout << "Error opening the file " << filename <<endl;
        return "";
    }

}

int& Submission::getDueDate()
{
    return *duedate;
}
void Submission::SumbitDueDate() {

    setData();
    int ptr[4];
    *ptr = getDueDate();

    fstream ofile("Duedate.txt");

    if (!ofile) {
        cout << "Error opening file!" << endl;
        return;
    }

    else
        ofile << ptr[0] << "," << ptr[1] << "," << ptr[2] << "," << ptr[3] << endl;

    ofile.close();

}

double Submission::getMarks()
{
    return marks;
}
void Submission::setMarks()
{
    cout << "enter marks :" << endl;
    cin >> marks;
    
}

void Submission::SumbitAssignment()
{
    
    string solution;
    
    solution = ReadAnswer();
    stringstream ss;
    if (solution != "")
    {
        ofstream outputFile("Submission.txt" ); 

        if (outputFile.is_open())
        {
            
            
           
            outputFile << "The solution is : " << endl;
            outputFile << solution;
            outputFile.close();
            cout << "Solution submitted successfully!" << endl;
        }
        else
        {
            cout << "Error opening the file for writing." << endl;
        }
    }
    else
    {
        cout << "No solution data to submit." << endl;
    }

}

void Submission::givefeedback()
{
    cout << "enter feedback:";
    cin >> Feedback;

    cout << "feedback Updated!" << endl;

}

void Submission::evaluate()
{
    string temp;
    cout << "Enter any thing for evaluation";
    cin >> temp;
    evaluatestatus = 1;
    cout << "evaluation status is " << evaluatestatus << endl;
    
    
}


void Submission::setAttachment(string f)
{
    this->fileattachment = f;
}

string Submission::getAttachment()
{
    return this->fileattachment;
}

void Submission::setFeedback(string feed)
{
    this->Feedback = feed;
}

string Submission::getFeedback()
{
    return this->Feedback;
}
/*
void Submission::setMarks()
{
    int marks;
    cout << "Enter marks for the student:";
    cin >> marks;

    assignment->setpointvalue(marks);
}

void Submission::viewMarks()
{
    cout << assignment->getPointvalue();
}
*/