#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

typedef long long ll;

ll bfs(ll N, ll M){
    ll p10[21];
    p10[0] = 1;
    for (int i = 1; i <= 20; i++)
        p10[i] = 10 * p10[i-1];
    
    set<ll> fila;
    unordered_set<ll> visitados;

    visitados.insert(N);
    fila.insert(N);

    long long power_m = 10, power_n = 10;
    while (power_m < M) power_m *= 10;
    while (power_n < N) power_n *= 10;
    long long upper_limit = power_n * power_m / 10;

    while (fila.size()){
        ll u = *(fila.begin());
        fila.erase(fila.begin());

        if (u % M == 0)
            return u;
        
         if (u >= upper_limit) continue;

        // adicionando a direita
        for (int d = 0; d <= 9; d++){
            ll v = u*10 + d;
            if (visitados.find(v) == visitados.end()){
                visitados.insert(v);
                fila.insert(v);
            }
        }
        // adicionando a esquerda
        int len = 0; ll aux = u;
        while (aux){
            len++;
            aux/=10;
        }
        for (int d = 1; d <= 9; d++){
            ll v = d*p10[len] + u;
            if (visitados.find(v) == visitados.end()){
                visitados.insert(v);
                fila.insert(v);
            }
        }
    }
    return -1;
}

int main(){
    ll N, M;
    while (cin >> N >> M)
    {
        cout << bfs(N, M) << endl;
    }
    return 0;
}