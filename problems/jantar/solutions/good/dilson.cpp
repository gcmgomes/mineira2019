#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

constexpr int MAXN = 1000001;

vector<int> g[MAXN];
int n, m;
bool sol[MAXN];
int head, nxt[MAXN], pre[MAXN];
int marked[MAXN];
int flag;

void buildCycle() {
  int a = 1;
  do {
    for (int b : g[a]) {
      if (b == pre[a]) continue;
      pre[b] = a;
      nxt[a] = b;
      a = b;
      break;
    }
  } while (not nxt[a]);
  head = a;
}

bool reduceCycle() {
  flag++;
  int a = head;
  int add = 0;
  int size = 0;

  do {
    
    for (int b : g[a]) {
      if (b == pre[a] or b == nxt[a]) continue;
      if (marked[a] == flag) {
        nxt[a] = b;
        pre[b] = a;
        head = a;
        return true;
      } else {
        marked[b] = flag;
      }
    }
    a = nxt[a];
  } while (a != head);

  flag++;
  do {
    size++;
    for (int b : g[a]) {
      if (b == pre[a] or b == nxt[a]) continue;
      if (marked[b] == flag) {
        add = b;
      } else {
        marked[b] = flag;
      }
    }
    a = nxt[a];
  } while (a != head);

  if (not add) return false;
  if (size < 4) return false;

  if (size == 4) {
    bool good = false;
    do {
      int cnt = 0;
      for (int b : g[a]) if (b == add) cnt++;
      for (int b : g[nxt[a]]) if (b == add) cnt++;
      if (cnt == 2) good = true;
      a = nxt[a];
    } while (a != head);

    if (not good) return false;
  }

  int p = 0, q = 0;
  do {
    for (int b : g[a]) {
      if (b == add) {
        p = q;
        q = a;
      }
    }
    a = nxt[a];
  } while (a != head);
  assert(p and q);

  int s1 = 0;
  a = p;
  while (a != q) {
    a = nxt[a];
    s1++;
  }

  int s2 = size - s1;

  if (s1 < s2) {
    nxt[add] = p;
    pre[p] = add;
    pre[add] = q;
    nxt[q] = add;
  } else {
    nxt[add] = q;
    pre[q] = add;
    nxt[p] = add;
    pre[add] = p;
  }
  head = p;
  
  return true;
}

bool grow() {
  for (int i = 1; i <= n; i++) {
    if (sol[i]) continue;
    int cnt = 0;
    for (int j : g[i]) {
      if (sol[j]) cnt++;
    }
    if (cnt > 1) {
     sol[i] = true;
     return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      sol[i] = true;
      return;
    }
  }

  buildCycle();
  while(reduceCycle());

  int a = head;
  do {
    sol[a] = true;
    a = nxt[a];
  } while (a != head);

  bool is_cycle = true;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() != 2) {
      is_cycle = false;
      break;
    }
  }
  if (is_cycle) {
    if (n == 3) return;

    sol[head] = sol[nxt[head]] = false;
  }
  while(grow());
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

  solve();

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
