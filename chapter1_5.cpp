/**********************************************************************
    Program Author:         Alexander Gonzales
    Program Date:           10/28/2016
    Program Description:    Chapter 1-5 Summary Assignment
**********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip> // for output manipulation
#include <cstdlib>
#include <cmath> // for rounding

using namespace std;

int main()
{
    string fname = "name"; //setup the strings for reading the file
    string lname = "unknown";
    double rate, totalInterest, amount, interest, interest2;
    int recordCount, years;
    int year = 1;
    cout << "Welcome to the Certificate of deposit report program\n"; //output to console start of program
    ifstream inputFile ("data.txt");     //open input file
    ofstream outputFile ("depositreport.txt"); //open output file
    if(inputFile.fail())     //if unable to open display error and exit
    {
        cout << "\t!!FAILED Open of Input File!!: data.txt\n";
        exit(1);
    }
    if(outputFile.fail())     //if unable to open display error and exit
    {
        cout << "\t!!FAILED Open of Output File!!: depositreport.txt\n";
        exit(1);
    }
    //output to console start processing records
    cout << "Starting to process records\n";

    outputFile << fixed << setprecision(5) << showpoint;

    //output report file the report header
    outputFile  << setw(50) << "Certificate of Deposit Report\n\n";
    outputFile  << left
                << setw(25) << "Name"
                << right
                << setw(5)  << "Rate"
                << setw(17) << "Balance"
                << setw(5)  << "Year"
                << setw(16) << "Interest\n";
    outputFile  << "-----------------------------------------------------------------\n";

    //loop until there are no more input lines
    recordCount = 0;

    while(inputFile >> fname >> lname >> amount >> years >> rate)
    {

        //increment record counter
        recordCount ++;

        //set total interest to zero
        totalInterest = 0;
        interest2 = 0;

        //output to console the record number you #include <cstdlib>are processing
        cout << "processing record: " << recordCount << endl;

        //output to report file the first last name and rate

        //for loop thru the number of years
        for(int i = 1; i <= years; i++)
        {
            //calculate interest
            if (amount < 1000)//if statement for amount under 1000 due to spacing error
            {
                interest = (rate * amount)/100;
                outputFile  << fixed << setprecision(2)
                            << left
                            << setw(25) << fname + " " +lname
                            << right
                            << setw(5)  << rate << "%"
                            << setw(10) << "$"  << amount
                            << setw(3)  << " "  << year
                            << setw(10) << "$"  << interest << "\n";
                amount = interest + amount;
                totalInterest = interest + interest2;
                interest2 = totalInterest;
                year ++;
            }
            if (amount >= 1000)//if statement for amount over 1000 due to spacing error
            {
                interest = (rate * amount)/100;
                outputFile  << fixed << setprecision(2)
                            << left
                            << setw(25) << fname + " " +lname
                            << right
                            << setw(5)  << rate << "%"
                            << setw(10) << "$" << amount
                            << setw(3)  << year
                            << setw(10) << "$" << interest << "\n";
                amount = interest + amount;
                totalInterest = interest + interest2;
                interest2 = totalInterest;
                year ++;
            }

        }
        year = 1;
        if (totalInterest < 100) //if statement for formatting if total interest is under 100 due to spacing error
        {
            outputFile  << fixed << setprecision(2)
                        <<"===================================================================\n"
                        << left
                        << setw(25) << " "
                        << right
                        << setw(5)  << " Total"
                        << setw(10) << " $" << amount
                        << setw(3)
                        << setw(10) << "\t\t$" << totalInterest << "\n\n";
        }
        if (totalInterest >= 100) //if statement for formatting if total interest is equal or over 100 due to spacing error
        {
            outputFile  << fixed << setprecision(2)
                        <<"===================================================================\n"
                        << left
                        << setw(25) << " "
                        << right
                        << setw(5)  << " Total"
                        << setw(10) << " $" << amount
                        << setw(3)
                        << setw(10) << "\t$" << totalInterest << "\n\n";
        }
    }
    //close both input and output files
    outputFile.close();
    inputFile.close();

    return 0;
}
