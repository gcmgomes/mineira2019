#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define BUFF ios::sync_with_stdio(false);
typedef long long int ll;
typedef long double ld;

#define MAXN 1000001

int vb[MAXN];
int vresp[MAXN];
int vparents[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int minb) {
  vresp[u] = minb;
  for (int v : graph[u]) {
    dfs(v, min(minb, vb[v]));
  }
}

int main() {
  BUFF;

  memset(vresp, INF, sizeof(vresp));
  int n, p, paidetodos = -1;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    vparents[i] = -1;
    if (p == -1) paidetodos = i;
    else {
      graph[p-1].pb(i);
      vparents[i] = p-1;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> p;
    vb[p-1] = i+1;
  }

  dfs(paidetodos, vb[paidetodos]);

  cout << vresp[0];
  for(int i = 1; i < n; i++) {
    cout << " " << vresp[i];
  }
  cout << endl;

  return 0;
}
