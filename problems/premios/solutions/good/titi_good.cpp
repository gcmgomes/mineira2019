#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct sTeam {
  int id, p, t;

  sTeam(int pid, int pp, int pt) : id(pid), p(pp), t(pt) {}

  bool operator<(const sTeam& other) const {
    if (p == other.p) return t < other.t;
    return p > other.p;
  }
} team;

int main() {
  ios::sync_with_stdio(false);
  int n, k;

  cin >> n >> k;
  vector<team> vteam;
  for(int i = 0; i < n; i++) {
    int id, p, t;
    cin >> id >> p >> t;
    vteam.push_back(sTeam(id, p, t));
  }
  sort(vteam.begin(), vteam.end());
  cout << vteam[k-1].id << endl;
  
  return 0;
}
