// Solucao do problema "Historia de Pescador"
// Andre Rodrigues da Cruz (dacruz@cefetmg.br)
// Maratona Mineira de Programacao 2019

#include <iostream>

using namespace std;

int main() {
    int quantidade, fator, pescados, i;
    
    cin >> quantidade >> fator;
    for(i = 1; i <= quantidade; i++) {
        cin >> pescados;
        cout << "Peixe " << i << ": " << pescados*fator << endl;
    }
    return 0;
}
