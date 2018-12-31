#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string firstName = "";
string lastName = "";
string phoneNum = "";

void lookup_name(string& firstName, string& lastName)
{
        string fname;
        string lname;
        ifstream inFile;
        string phNum;
        inFile.open("inFile.txt");
        while ( !inFile.eof() )
        {
                inFile >> fname >> lname >> phNum;
                if ( fname == firstName && lname == lastName )
                {
                        phoneNum =  phNum;
                        break;
                }
                cout << phoneNum << endl << endl;
        }
        inFile.close();
}

int main()
{
        char quit='Y';
        while ( quit=='Y' || quit=='y' )
        {
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                lookup_name(firstName, lastName);
                if ( phoneNum != "")
                        cout << "The phone requested is" << phoneNum << endl;
                else
                        cout << "Not found" << endl;
                cout << "Do you want t0 look up another entry in the directory [Y/N]?   ";
                cin >>  quit;
		phoneNum = "";
        }
}
