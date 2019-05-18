#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool checkBits(const vector<int>& ord) {
  const int n = ord.size();
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (ord[j] > ord[i]) cnt++;
    }
    for (int j = i + 1; j < n; j++) {
      if (ord[j] < ord[i]) cnt++;
    }
    if (cnt % 2) return false;
  }
  return true;
}

bool checkConnections(const vector<int>& ord, const vector<pair<int, int>>& con) {
  const int n = ord.size();
  for (const auto& c : con) {
    if (ord[c.first] != c.second) return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> con(m);
  for (auto& c : con) {
    cin >> c.first >> c.second;
    c.first--;
    c.second--;
  }
  int ans = 0;
  vector<int> ord(n);
  for (int i = 0; i < n; i++) ord[i] = i;
  do {
    if (checkConnections(ord, con) and checkBits(ord)) ans++;
  } while (next_permutation(ord.begin(), ord.end()));

  cout << ans << endl;
}
