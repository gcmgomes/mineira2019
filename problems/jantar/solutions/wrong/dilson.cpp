#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1000001;

vector<int> g[MAXN];
int n, m;
int ord[MAXN];
bool sol[MAXN];

void work() {
 
  for (int i = 0; i < n; i++) ord[i] = i + 1;
  int cnt_true = 0;
  int cnt_false = n;

  for (int rep = 0; rep < 100; rep++) {
    random_shuffle(ord, ord + n);
    bool changed = false;
    for (int i = 0; i < n; i++) {
      int k = ord[i];
      if (cnt_true == 0) {
        sol[k] = true;
        changed = true;
        cnt_true++;
        cnt_false--;
      } else if (cnt_false == 0) {
        sol[k] = false;
        changed = true;
        cnt_false++;
        cnt_true--;
      } else {
        int cand[4];
        int ncand = 0;
        cand[ncand++] = k;
        for (int j : g[k]) if (sol[j] != sol[k]) cand[ncand++] = j;
        if (ncand > 2) {
          int x = cand[lrand48() % ncand];
          if (sol[x]) {
            sol[x] = false;
            cnt_true--;
            cnt_false++;
          } else {
            sol[x] = true;
            cnt_true++;
            cnt_false--;
          }
          changed = true;
        }
      }
    }
    if (not changed) return;
  }
  for (int i = 1; i <= n; i++) sol[i] = false;
}


void printSide(bool side) {
  bool first = true;
  
  int size = 0;
  for (int i = 1; i <= n; i++) if (sol[i] == side) size++;
  cout << size << '\n';

  for (int i = 1; i <= n; i++) {
    if (sol[i] != side) continue;
    if (not first) cout << ' ';
    first = false;
    cout << i;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  work();

  int total = 0;
  for (int i = 1; i <= n; i++) if (sol[i]) total++;

  if (total == 0 or total == n) {
    cout << 0 << endl;
    return 0;
  }

  cout << 1 << '\n';
  printSide(true);
  printSide(false);
}
