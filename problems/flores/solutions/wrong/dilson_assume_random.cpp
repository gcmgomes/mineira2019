#include <iostream>

using namespace std;

constexpr int MAXN = 1000;

int x[MAXN][MAXN];

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  int mask = (1 << t) - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x[i][j];
      x[i][j] &= mask;
    }
  }


  for (int L = 1; L <= 6; L++) {
    for (int i = 0; i + L - 1 < n; i++) {
      for (int j = 0; j + L - 1 < m; j++) {
        int get = 0;
        for (int ip = i; ip < i + L; ip++) {
          for (int jp = j; jp < j + L; jp++) {
            get |= x[ip][jp];
          }
        }
        if (get == mask) {
          cout << L * L << '\n';
          cout << i << ' ' << j << '\n';
          return 0;
        }
      }
    }
  }
  cout << -1 << '\n';
}
