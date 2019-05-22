#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<int> c(n, -1);
  vector<bool> used_b(n);
  int forbidden[] = {0, 0};
  int count[] = {(n+1)/2, n/2};

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    if (used_b[b-1] || c[a-1] != -1) {
      cout << "0\n";
      return 0;
    }

    c[a-1] = b-1;
    used_b[b-1] = true;
    forbidden[(b - 1)%2]++;
  }

  long long ans = 1;

  for (int i = 0; i < n; i++) {
    if (c[i] != -1) {
      if (c[i] % 2 != i % 2) {
        ans = 0;
        break;
      }
      count[0]--;
      forbidden[0]--;
    } else {
      int choices = count[0] - forbidden[0];
      if (!choices) {
        ans = 0;
        break;
      }
      ans *= choices;
      ans %= MOD;
      count[0]--;
    }

    swap(forbidden[0], forbidden[1]);
    swap(count[0], count[1]);
  }

  cout << ans << endl;

  return 0;
}
