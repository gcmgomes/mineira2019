#include <iostream>

using namespace std;

const int MAXN = 1000;

int used[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  if (n > MAXN) while(true);

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    used[x - 1][y - 1] = 1;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (used[i][j]) continue;
      ans++;
      for (int k = i + 1; k < n; k++) {
        if (used[k][j]) break;
        ans++;
      }
      for (int k = j + 1; k < n; k++) {
        if (used[i][k]) break;
        ans++;
      }
    }
  }
  
  cout << ans << endl;
}
