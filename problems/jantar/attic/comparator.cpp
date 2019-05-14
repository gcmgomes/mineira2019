#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int INF = std::numeric_limits<int>().max();
double INFD = std::numeric_limits<double>().max();
int ERR = -1, ACCEPTED = 4;

double PI = acos(-1);

bool HasIntersection(vector<set<int>>& parts) {
  int i = (parts[0].size() < parts[1].size()) ? 0 : 1;
  for (auto& x : parts[i]) {
    if (parts[1 - i].count(x)) {
      return 1;
    }
  }
  return 0;
}

bool IsMatchingCut(vector<vector<int>>& graph, vector<set<int>>& parts) {
  int i = 0;
  while (i < 2) {
    for (auto& x : parts[i]) {
      int c = 0;
      for (auto& y : graph[x]) {
        c += parts[1 - i].count(y);
      }
      if (c > 1) {
        return false;
      }
    }
    i++;
  }
  return true;
}

int main(int argc, char** argv) {
  ifstream judge(argv[2]);
  freopen(argv[3], "r", stdin);  // read problem input
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  vector<vector<int>> graph(n);
  int i = 0;
  while (i < m) {
    int u = 0, v = 0;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
    i++;
  }
  int judge_status = 0, team_status = 0;
  judge >> judge_status;
  judge.close();
  freopen(argv[1], "r", stdin);  // read team solution.
  scanf("%d", &team_status);
  if (!judge_status) {
    if (team_status) {
      fprintf(stderr,
              "No matching cut actually exists, team said there was one.\n");
      return ERR;  // whatever is the error code for boca/box.
    }
    return ACCEPTED;
  }
  if (!team_status) {
    fprintf(stderr, "Team couldn't find a matching cut.\n");
    return ERR;
  }
  vector<set<int>> parts(2);
  vector<int> ps(2);
  int j = 0;
  for (auto& x : parts) {
    scanf("%d", &ps[j]);
    i = 0;
    while (i < ps[j]) {
      int u = 0;
      scanf("%d", &u);
      u--;
      parts[j].insert(u);
      i++;
    }
    j++;
  }
  if (!ps[0] || !ps[1] || ((ps[0] + ps[1]) != n) ||
      HasIntersection(parts)) {  // not a non-trivial partition
    fprintf(stderr, "Team solution is not a (trivial) partition.\n");
    return ERR;
  }
  if (!IsMatchingCut(graph, parts)) {  // not a matching cut
    fprintf(stderr, "Team solution is not a matching cut.\n");
    return ERR;
  }
  return ACCEPTED;
}
