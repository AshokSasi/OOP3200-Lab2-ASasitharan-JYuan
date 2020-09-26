// OOP3200-F2020-Lab2-ASasitharan-JYuan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Title:  OOP 3200 Lab 2 - Class Operators and Data Type Conversions
// Made by: Jacky Yuan, 100520106
//          Ashok Sasitharan, 100745484
// Date Created: Sept 18, 2020
// Description: Program used to generate and track work tickets for client requests.
//
// Change Log: Sept 25, 2020 - Modified class operators and data type conversions as per lab 2
//

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <string>
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;
int iteration = 1;

class WorkTicket
{
public:

    //constructor
    WorkTicket(int ticketNumber = 0, string clientID = "", int workTicketDay = 1, int workTicketMonth = 1, int workTicketYear = 2000, string issueDescription = "");

    friend std::ostream& operator<<(std::ostream& out, const  WorkTicket& ticket);
    //friend std::istream& operator>>(std::istream& in, WorkTicket& ticket);

    //copy constructor
    WorkTicket(const WorkTicket& newTicket);

    //comparsion constructor
    bool operator==(const WorkTicket& otherTicket) const;

    // Accessors:
    //get the work ticket number
    int GetWorkTicketNumber() const;
    //get the client ID
    string GetClientID() const;
    //get the work ticket date
    int GetWorkTicketDay() const;
    //get the work ticket month
    int GetWorkTicketMonth() const;
    //get the work ticket year
    int GetWorkTicketYear() const;
    //get the clients problem description
    string GetIssueDescription() const;
    //returns the ticket attributes
    string ShowWorkTicket() const;


    //Mutators:
    // set ticket number
    void SetWorkTicketNumber(int ticketNumber);
    // set client ID
    void SetClientID(string clientID);
    // set work ticket Date
    void SetWorkTicketDay(int workTicketDay);
    // set work ticket Month
    void SetWorkTicketMonth(int workTicketMonth);
    // set work ticket Year
    void SetWorkTicketYear(int workTicketYear);
    // set issue Description
    void SetIssueDescription(string issueDescription);
    // set work ticket
    bool SetWorkTicket(int ticketNumber, string clientID, int workTicketDay, int workTicketMonth, int workTicketYear, string issueDescription);


private:
    int ticketNumber; //work ticket number variable
    string clientID; // client ID variable
    int workTicketDay;//work ticket day variable
    int workTicketMonth;//work ticket month variable
    int workTicketYear;//work ticket year variable
    string issueDescription; //issue description variable

};


int main()
{
    //constants
    const int NUMBER_OF_OBJECTS = 3;
    const int MIN_DATE = 1;
    const int MAX_DATE = 31;
    const int MIN_MONTHS = 1;
    const int MAX_MONTHS = 12;
    const int MIN_YEARS = 2000;
    const int MAX_YEARS = 2099;
    const int MIN_TICKET_NUMBER = 1;

    //Variable Declarations
    int inputtedTicketNumber;
    string inputtedClientID;
    int inputtedWorkTicketDay;
    int inputtedWorkTicketMonth;
    int inputtedWorkTicketYear;
    string inputtedIssueDescription;
    WorkTicket workTicketObj[NUMBER_OF_OBJECTS];
    bool errorFlag = false;
    string equalTicket;

    //INPUT SECTION
    for (int i = 0; i < NUMBER_OF_OBJECTS; i++)//loops through array of ticket objects
    {
        cout << "\nWork Ticket #" << i + 1; //header for ticket
        while (errorFlag == false) //loops the input section when invalid input is entered
        {
            try//start of try block
            {
                cout << "\nEnter the work ticket number: "; //prompt input for ticket number

                inputtedTicketNumber = ConsoleInput::ReadInteger(MIN_TICKET_NUMBER); //user input for ticket's date


                cout << "\nEnter the Client ID: "; //prompt input for the client id
                cin >> inputtedClientID; //user input for client id

                cout << "\nEnter the date: "; // prompt input for the ticket's date
                inputtedWorkTicketDay = ConsoleInput::ReadInteger(MIN_DATE, MAX_DATE); //user input for ticket's date

                cout << "\nEnter the month as a number between 1-12: "; // prompt input for the ticket's month
                inputtedWorkTicketMonth = ConsoleInput::ReadInteger(MIN_MONTHS, MAX_MONTHS); //input for ticket's month

                cout << "\nEnter the year (must be between 2000-2099): "; //prompt input for the ticket's year
                inputtedWorkTicketYear = ConsoleInput::ReadInteger(MIN_YEARS, MAX_YEARS); // user input for the ticket's year

                cout << "\nEnter description of the issue: "; //prompt user for issue description
                getline(cin, inputtedIssueDescription); //user inputs description of issue

                //set error flag equal to the return value of SetWorkTicket function for this ticket object
                errorFlag = workTicketObj[i].SetWorkTicket(inputtedTicketNumber, inputtedClientID, inputtedWorkTicketDay, inputtedWorkTicketMonth, inputtedWorkTicketYear, inputtedIssueDescription);

                // if (errorFlag == false)
               //  {
                //     cout << "\nClient ID and issue description fields cannot be empty." << endl;
               //  }

                if (errorFlag == true)
                {
                    if (i == 0)
                    {
                        WorkTicket newTicket = workTicketObj[i];
                    }
                    cout << "\nPress enter to continue" << endl;
                    cin.ignore();
                    system("CLS");

                }


            }
            catch (const invalid_argument& ia)  //catch block
            {
                cerr << "Invalid argument: " << ia.what() << '\n'; //invalid argument print
               //clears input
                cin.clear();
                //syncs input
                cin.sync();

            }


        }
        errorFlag = false; //resets errorFlag back to false
    }


    for (int j = 0; j < NUMBER_OF_OBJECTS; j++)//loops through the array of objects to print them out
    {
        cout << workTicketObj[j] << endl; //calls ShowWorkTicket method for each object
    }

    if (workTicketObj[0] == workTicketObj[1])
    {
        equalTicket = "True";
    }
    else
    {
        equalTicket = "False";
    }

    cout << "Is ticket #1 equal to ticket #2? " << equalTicket << endl;

    return 0;
}//end of main

//CLASS DEFINITION SECTION


//generates a work ticket object
WorkTicket::WorkTicket(const int inputtedTicketNumber, const string inputtedClientID, const int inputtedWorkTicketDay, const int inputtedWorkTicketMonth, const int inputtedWorkTicketYear, const string inputtedIssueDescription)
{
    //calls SetWorkTicket method
    SetWorkTicket(inputtedTicketNumber, inputtedClientID, inputtedWorkTicketDay, inputtedWorkTicketMonth, inputtedWorkTicketYear, inputtedIssueDescription);
}

//setter for each work ticket parameter
bool WorkTicket::SetWorkTicket(int inputtedTicketNumber, string inputtedClientID, int inputtedWorkTicketDay, int inputtedWorkTicketMonth, int inputtedWorkTicketYear, string inputtedIssueDescription)
{
    if (inputtedIssueDescription.empty() == false && inputtedClientID.empty() == false) //run if the issue description isn't empty and the client ID isn't empty
    {
        SetWorkTicketNumber(inputtedTicketNumber);
        // set client ID
        SetClientID(inputtedClientID);
        // set work ticket Day
        SetWorkTicketDay(inputtedWorkTicketDay);
        // set work ticket Month
        SetWorkTicketMonth(inputtedWorkTicketMonth);
        // set work ticket Year
        SetWorkTicketYear(inputtedWorkTicketYear);
        // set issue Description
        SetIssueDescription(inputtedIssueDescription);

        return true;
    }
    else
    {
        return false;
    }
}

//Copy constructor
WorkTicket::WorkTicket(const WorkTicket& newTicket)
{
    SetWorkTicket(newTicket.GetWorkTicketNumber(), newTicket.GetClientID(), newTicket.GetWorkTicketDay(),
        newTicket.GetWorkTicketMonth(), newTicket.GetWorkTicketYear(), newTicket.GetIssueDescription());

    cout << "\nA work ticket object was copied\n";
}

//friend method for operator<< overload
std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket)
{
    out << ticket.ShowWorkTicket();
    return out;
}

////friend method for operator<< overload
//std::istream& operator>>(std::istream& in, WorkTicket& ticket)
//{
//
//    in >> point.m_x;
//    in.ignore();
//    in >> point.m_y;
//    return in;
//}

bool WorkTicket::operator==(const WorkTicket& otherTicket) const
{
    return ((GetWorkTicketNumber() == otherTicket.GetWorkTicketNumber()) && (GetClientID() == otherTicket.GetClientID())
        && (GetWorkTicketDay() == otherTicket.GetWorkTicketDay()) && (GetWorkTicketMonth() == otherTicket.GetWorkTicketMonth())
        && (GetWorkTicketYear() == otherTicket.GetWorkTicketYear()) && (GetIssueDescription() == otherTicket.GetIssueDescription()));
}
//setter for the work ticket number
void WorkTicket::SetWorkTicketNumber(int inputtedTicketNumber)
{
    ticketNumber = inputtedTicketNumber;
}

//setter for the client ID
void WorkTicket::SetClientID(string inputtedClientID)
{
    clientID = inputtedClientID;
}

//setter for workTicketDay
void WorkTicket::SetWorkTicketDay(int inputtedWorkTicketDay)
{
    workTicketDay = inputtedWorkTicketDay;
}

//setter for the work ticket month
void WorkTicket::SetWorkTicketMonth(int inputtedWorkTicketMonth)
{
    workTicketMonth = inputtedWorkTicketMonth;
}

//setter for the work ticket year
void WorkTicket::SetWorkTicketYear(int inputtedWorkTicketYear)
{
    workTicketYear = inputtedWorkTicketYear;
}

//setter for the work ticket description
void WorkTicket::SetIssueDescription(string inputtedIssueDescription)
{
    issueDescription = inputtedIssueDescription;
}

//getter function for work ticket number
int WorkTicket::GetWorkTicketNumber() const
{
    return ticketNumber;
}

//getter function for work client ID
string WorkTicket::GetClientID() const
{
    return clientID;
}

//getter function for work ticket day
int WorkTicket::GetWorkTicketDay() const
{
    return workTicketDay;
}

//getter function for work ticket Month
int WorkTicket::GetWorkTicketMonth() const
{
    return workTicketMonth;
}

//getter function for work ticket year
int WorkTicket::GetWorkTicketYear() const
{
    return workTicketYear;
}

//getter function for issue description
string WorkTicket::GetIssueDescription() const
{
    return issueDescription;
}

//shows the attributes of a work tickets issue
string WorkTicket::ShowWorkTicket() const
{   // declare a stringstream object
    stringstream workTicketOutput;
    // build the workorder output
    workTicketOutput << "Work Ticket # " << iteration << " - " << GetClientID()
        << " (" << GetWorkTicketDay() << "/" << GetWorkTicketMonth() << "/" << GetWorkTicketYear()
        << "): " << GetIssueDescription() << endl;
    //return the workorder attribute output
    iteration++;
    return workTicketOutput.str();
}
