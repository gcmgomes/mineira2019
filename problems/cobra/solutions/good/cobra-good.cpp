// Solucao do problema "Cobra de Dominos"
// Andre Rodrigues da Cruz (dacruz@cefetmg.br)
// Maratona Mineira de Programacao 2019

#include <iostream>

using namespace std;

int main()
{
    long n;
    int i = 1;

    while(true)
    {
        cin >> n;
        if(n == 0) break;
        cout << "Caso " << i++ << ": " << ((n%2 ? -1 : 1)*(2-n) + 2 + n + 2*n*n)/4 << endl;
    }

    return 0;
}