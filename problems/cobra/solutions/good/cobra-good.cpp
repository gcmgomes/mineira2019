#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long n, i = 1;

    while(true)
    {
        cin >> n;
        if(n == 0) break;
        n = (pow(-1, n)*(2-n) + 2 + n + 2*pow(n, 2))/4;
        cout << "Caso " << i++ << ": " << n << endl;
    }

    return 0;
}