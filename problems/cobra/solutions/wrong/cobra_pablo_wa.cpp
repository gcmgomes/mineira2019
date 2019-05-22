#include <iostream>
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
    int n = 0;
    cin >> n;
    cout << v[n] << endl;

  return 0;
}
