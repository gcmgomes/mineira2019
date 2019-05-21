#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<string, vector<string>> in;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    
    if (a == b) {
      cout << 1 << '\n' << a << '\n';
      return 0;
    }

    in[b].push_back(a);
  }

  vector<string> sol;
  for (auto& e : in) {
    if (e.second.size() != 2) continue;

    for (auto& x : e.second) {
      if (in.count(x)) sol.push_back(x);
    }
  }

  sort(sol.begin(), sol.end());
  cout << sol.size() << '\n';
  for (auto& name : sol) {
    cout << name << '\n';
  }
}
