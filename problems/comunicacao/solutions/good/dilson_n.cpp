#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

constexpr ll MOD = 1.e9+7;

ll factorial(int k) {
  ll val = 1;
  for (int i = 1; i <= k; i++) {
    val = val * i % MOD;
  }
  return val;
}

int main() {
  int n, m;
  cin >> n >> m;
  int cnt[2];
  cnt[1] = n / 2;
  cnt[0] = n - cnt[1];
  vector<bool> a_used(n), b_used(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a_used[a] or b_used[b] or a % 2 != b % 2) {
      cout << 0 << '\n';
      return 0;
    }
    a_used[a] = true;
    b_used[b] = true;
    cnt[a % 2]--;
  }

  ll ans_even = factorial(cnt[0]);
  ll ans_odd = factorial(cnt[1]);
  ll ans = ans_even * ans_odd % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}
