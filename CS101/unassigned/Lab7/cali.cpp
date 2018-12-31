#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//  Demonstration: Portion of Calendar application. InFile is read with month name and number of days.
//  Set the weekday to the intial entry then allow it to be reset by the return value of PrintMonth.
//  Last weekday of previous month is used to set the weekday for next call to PrintMonth until EOF.


void PrintHeader(string mon)
{
        cout << "\t\t\t" << mon << endl << endl;
        cout << "\tSun\tMon:\tTue:\tWed:\tThr:\tFri:\tSat:" << endl << endl;
}

int PrintMonth(int day, int max)
{
        int prev = 0;
        while (prev < day)
        {
                cout << "\t";
                prev++;
        }
        int date = 1;
        int i = day;
        while (date <= max)
        {
                while ( i < 7 )
                {
                        cout << "\t" << date++;
                        day = i++;
                        if ( date > max )
                        {
                                day = i%7;
                                break;
                        }
                }
                i = 0;
                cout << endl;
        }
        return day;
}

int main()
{
        ifstream inFile;
        inFile.open("inFile.txt");
        string month;
        int year;
        int wkday;
        int numDays;
        cout<<"Enter Year   : ";
        cin>>year;
        cout<<"Enter 0-6 for the week January 1st falls on. 0-Sun, 1-Mon, 2-Tue, 3-Wed, 4-Thr, 5-Fri, 6-Sat   : ";
        cin>>wkday;
        cout << endl << endl << "\t\t\tYEAR  --  " << year << endl << endl;
        while (!inFile.eof())
        {
                inFile >> month >> numDays;
                PrintHeader(month);
                wkday = PrintMonth(wkday, numDays);
        }
        inFile.close();
        return 0;
}
