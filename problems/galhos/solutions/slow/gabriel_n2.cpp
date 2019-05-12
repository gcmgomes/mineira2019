#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &g, int v, vector<int> &time, int t) {
  time[v] = min(time[v], t);

  for (int u : g[v])
    dfs(g, u, time, t);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<vector<int>> g(N);

  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    if (p != -1) {
      g[p - 1].push_back(i);
    }
  }

  vector<int> time(N, N);

  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    dfs(g, v - 1, time, i + 1);
  }

  for (int i = 0; i < N; i++) {
    cout << time[i] << (i + 1 == N ? '\n' : ' ');
  }

  return 0;
}
