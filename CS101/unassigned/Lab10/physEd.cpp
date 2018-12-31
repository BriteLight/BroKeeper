#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct StudentType
{
        int Id;
        string Name;
        char Year;
        char Health;
        float Gpa;
};

void PrintResults(struct StudentType JVteam)
{
        cout << "Student Name:\tStudent ID:\tFRESHMAN\tSOPHOMORE\tJUNIOR\tSENIOR\tEXCELLENT\tGOOD\tFAIR\tPOOR\tGPA" << endl;
        cout << JVteam.Name << "\t\t" << JVteam.Id << "\t";
        switch(JVteam.Year)
        {
                case'f':
                        cout << "\t" << JVteam.Year << "\t\t\t\t\t";
                        break;
                case'n':
                        cout << "\t\t\t" << JVteam.Year << "\t\t\t";
                        break;
                case'j':
                        cout << "\t\t\t\t\t" << JVteam.Year << "\t";
                        break;
                case's':
                        cout << "\t\t\t\t\t\t" << JVteam.Year;
                        break;
        }
        switch(JVteam.Health)
        {
                case'e':
                        cout << "\t" << JVteam.Health << "\t\t\t\t";
                        break;
                case'g':
                        cout << "\t\t\t" << JVteam.Health << "\t\t";
                        break;
                case'f':
                        cout << "\t\t\t\t" << JVteam.Health << "\t";
                        break;
                case'p':
                        cout << "\t\t\t\t\t" << JVteam.Health;
                        break;
        }
        cout << "\t" << JVteam.Gpa << endl;
}

int main ()
{
        StudentType Team;
        string entry;
        cout << "Enter Last Name: ";
        cin >> entry;
        ifstream inFile;
        inFile.open("inFile.txt");
        while ( !inFile.eof() )
        {
                inFile >> Team.Id >> Team.Name >> Team.Year >> Team.Health >> Team.Gpa;
                if ( Team.Name == entry )
                {
                        PrintResults(Team);
                        break;
                }
        }
        inFile.close();
}
