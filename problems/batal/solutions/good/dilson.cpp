#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

constexpr int MAXN = 1.e6;

vector<int> rows[MAXN], cols[MAXN];

ll calc(vector<int>& line) {
  ll cnt = 0;
  int last = -1;
  for (auto& x : line) {
    ll size = x - last - 1;
    cnt += size * (size + 1) / 2;
    last = x;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    rows[x].push_back(y);
    cols[y].push_back(x);
  }

  for (int i = 0; i < N; i++) {
    sort(rows[i].begin(), rows[i].end());
    rows[i].push_back(N);
    sort(cols[i].begin(), cols[i].end());
    cols[i].push_back(N);
  }

  ll ans = 0;
  for (auto& row : rows) ans += calc(row);
  for (auto& col : cols) ans += calc(col);
  ans -= ll(N) * N - Q;

  cout << ans << endl;
}
