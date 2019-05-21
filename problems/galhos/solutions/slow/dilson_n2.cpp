#include <iostream>

using namespace std;

constexpr int MAXN = 212345;

int p[MAXN];
int t[MAXN];
int n;

int main() {
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (p[i] == -1) p[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    t[b] = i;
  }
  t[0] = n;

  bool changed;
  do {
    changed = false;
    for (int i = 1; i <= n; i++) {
      if (t[p[i]] < t[i]) {
        t[i] = t[p[i]];
        changed = true;
      }
    }
  } while (changed);

  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << ' ';
    cout << t[i];
  }
  cout << endl;
}
