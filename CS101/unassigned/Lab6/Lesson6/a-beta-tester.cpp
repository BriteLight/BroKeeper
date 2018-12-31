#include <iostream>
using namespace std;

void DoThis(int& alpha, int beta)
{
        int temp;
        alpha = alpha + 10;
        temp = beta;
        beta = 99;
}

int main()
{
        int gamma = 10;
        int delta = 20;
        DoThis(gamma, delta);
        cout << "gamma is now: " << gamma << "    " << "delta is now: " << delta << "\n";
        return 0;
}
