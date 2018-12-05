#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void get_tutor_data (ifstream&, string[], int[][13]);
string lookup_tutors(string[], int [][13], string);
void display_tutor_list(string);


void get_tutor_data (ifstream&, string[], int[][13])
{
      ifstream inFile;
      inFile.open("inFile.txt");
      int record=0;
      while ( !inFile.eof() )
      {
              inFile >> string[record];
      }
}



string lookup_tutors(string[], int [][13], string)
{
	"" 
}

void display_tutor_list(string)
{
	""
}


void main()
{
	string Tutor_name_array[];
	string Tutoring_array[][];
	for (int i=0;i

