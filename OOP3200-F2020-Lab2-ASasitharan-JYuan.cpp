// OOP3200-Lab1-Jacky-Ashok.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Title:  OOP 3200 Lab 1 - Review of Classes and Objects
// Made by: Jacky Yuan, 100520106
//          Ashok Sasitharan, 100745484
// Date: Sept 18, 2020
// Description: Program used to generate and track work tickets for client requests.
// Last Modified: N/A
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


class WorkTicket
{
public:

    //constructor
    WorkTicket(int ticketNumber = 0, string clientID = "", int workTicketDay = 1, int workTicketMonth = 1, int workTicketYear = 2000, string issueDescription = "");


    // Accessors:
    //get the work ticket number
    int GetWorkTicketNumber();
    //get the client ID
    string GetClientID();
    //get the work ticket date
    int GetWorkTicketDay();
    //get the work ticket month
    int GetWorkTicketMonth();
    //get the work ticket year
    int GetWorkTicketYear();
    //get the clients problem description
    string GetIssueDescription();
    //returns the ticket attributes
    string ShowWorkTicket();


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
        cout << "\n Work Ticket #" << j + 1 << endl; //ticket header
        cout << workTicketObj[j].ShowWorkTicket() << endl; //calls ShowWorkTicket method for each object
    }
    return 0;
}//end of main

//CLASS DEFINITION SECTION


//generates a work ticket object
WorkTicket::WorkTicket(int inputtedTicketNumber, string inputtedClientID, int inputtedWorkTicketDay, int inputtedWorkTicketMonth, int inputtedWorkTicketYear, string inputtedIssueDescription)
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
int WorkTicket::GetWorkTicketNumber()
{
    return ticketNumber;
}

//getter function for work client ID
string WorkTicket::GetClientID()
{
    return clientID;
}

//getter function for work ticket day
int WorkTicket::GetWorkTicketDay()
{
    return workTicketDay;
}

//getter function for work ticket Month
int WorkTicket::GetWorkTicketMonth()
{
    return workTicketMonth;
}

//getter function for work ticket year
int WorkTicket::GetWorkTicketYear()
{
    return workTicketYear;
}

//getter function for issue description
string WorkTicket::GetIssueDescription()
{
    return issueDescription;
}

//shows the attributes of a work tickets issue
string WorkTicket::ShowWorkTicket()
{   // declare a stringstream object
    stringstream workTicketOutput;
    // build the workorder output
    workTicketOutput << "Ticket Number:\t\t" << GetWorkTicketNumber() << "\nClient ID:\t\t" << GetClientID()
        << "\nWork Ticket Date:\t" << GetWorkTicketDay() << "/" << GetWorkTicketMonth() << "/" << GetWorkTicketYear()
        << "\nIssue Description:\t" << GetIssueDescription() << ".";
    //return the workorder attribute output
    return workTicketOutput.str();
}
