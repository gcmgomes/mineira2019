#include <iostream>
using namespace std;

#define endl "\n"
#define mp make_pair
#define pb push_back
typedef long long int ll;
typedef long double ld;

int main() {
  
  ll m, n;
  
  cin >> m >> n;
  for(int i = 0; i < m; i++) {
    ll a;
    cin >> a;
    cout << "Peixe " << (i+1) << ": " << a*n << endl;
  }
  
  
  return 0;
}
