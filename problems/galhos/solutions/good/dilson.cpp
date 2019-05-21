#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 212345;
vector<int> g[MAXN];
int tim[MAXN];
int n, r;

void dfs(int a, int t) {
  t = min(t, tim[a]);
  tim[a] = t;
  for (int b : g[a]) dfs(b, t);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p == -1) {
      r = i;
    } else {
      g[p - 1].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    tim[b - 1] = i + 1;
  }

  dfs(r, tim[r]);

  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << tim[i];
  }
  cout << endl;
}
