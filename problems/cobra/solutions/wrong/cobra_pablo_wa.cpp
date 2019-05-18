#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001
typedef long long int ll;

ll v[MAXN];

int main() {
  ios::sync_with_stdio(false);

  v[0] = 1;
  v[1] = 3;
  v[2] = 6;
  v[3] = 9;
  v[4] = 15;

  for(int i = 8; i < MAXN; i++) {
    if(i%2 == 0) {
      v[i] = (i+1)*(i+2)/2;
    } else {
      v[i] = v[i-1]+3+(i-2)/2;
    }
  }

  ll n, teste=1;
  while(true) {
    cin >> n;
    if(!cin) break;
    if(n == 0) break;
    
    cout << "Caso " << teste++ << ": " << v[n-1] << endl;
  }

  return 0;
}
