#include <iostream>
#include <iomanip>

using namespace std;

struct Pair
{
        double start_miles_num;
        double total_hours;
};

struct Pair GetData(struct Pair travlog)
{
        cout << "Enter the numer miles: ";
        cin >> travlog.start_miles_num;
        cout << "Enter the number of hours: ";
        cin >> travlog.total_hours;
        Pair t = { travlog.start_miles_num, travlog.total_hours };
        return t;
}

void PrintData(struct Pair input)
{
        double mph = input.start_miles_num / input.total_hours;
        cout << "The number of miles is " << fixed << setprecision(1) << setw(15) << input.start_miles_num << endl;
        cout << "The number of hours is " << setw(10) << input.total_hours << endl;
       cout << " The number of miles per hour is " << setw(15) << mph << endl;
}

int main ()
{
        Pair trip;
        Pair newset = GetData(trip);
        PrintData(newset);
}
