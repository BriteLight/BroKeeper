#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void get_user_input(char&, int&, int&, int&, int&);
float compute_item_cost(char&, int&, int&, int&, int&);
char proceed = 'Y';

void get_user_input(char& type, int& quantity, int& xinch, int& yinch, int& zinch)
{
        switch (type)
        {
                case'T':
                        proceed = 'T';
                        break;
                default:
                cout <<"Enter item (Wood type  --  number of pieces  --  width  --  height  --  length)" << endl;
                cin >> type >> quantity >> xinch >> yinch >> zinch;
        }
}


float compute_item_cost(char& wtyp, int& num, int& x, int& y, int& z)
{
        string woodtype;
        float unitprice;
        float cost;
        ifstream inFile;
        inFile.open("infile.txt");
        while ( !inFile.eof() )
        {
                inFile >> woodtype >> unitprice;
                if (woodtype.find(wtyp) == 0)
                {
                        cost = num * x * y * z * unitprice / 144;
                        cout << num << " "<< x <<"X" << y << "X" << z << " " << wtyp << " cost : $" << cost << endl;
                        break;
                }
        }
        inFile.close();
        return cost;
}

int main()
{
        float subtotal = 0;
        float tally = 0;
        int pieces, width, height, length;
        char wood;
        while ( proceed != 'T')
        {
                get_user_input(wood, pieces, width, height, length);
                if ( proceed != 'T')
                {
                        subtotal = compute_item_cost(wood, pieces, width, height, length);
                        tally = subtotal + tally;
                }
        }
        cout << "Total Cost is $" << tally <<endl;
}
