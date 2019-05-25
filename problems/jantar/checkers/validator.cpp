#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <set>
#include <vector>

#include "testlib.h"
using namespace std;


int dfs(const vector<vector<int> > &graph) {
  vector<bool> visited(graph.size(), false);
  stack<int> s;
  int cnt = 0;

  s.push(0);
  while(!s.empty()) {
    int cur = s.top();
    s.pop();
    visited[cur] = true;
    cnt++;

    for(int v : graph[cur]) {
      if(!visited[v]) {
        visited[v] = true;
        s.push(v);
      }
    }
  }
  return cnt;
}

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n, m;
  vector<vector<int> > graph;

  n = inf.readInt(2, 1000000);
  inf.readSpace();
  m = inf.readInt(1, 3*n/2);
  inf.readEoln();

  graph.resize(n);
  
  for(int i = 0; i < m; i++) {
    int u, v;
    u = inf.readInt(1, n);
    inf.readSpace();
    v = inf.readInt(1, n);
    inf.readEoln();

    u--;  v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  // Ensure that the graph is connected.
  ensure(dfs(graph) == n);

  inf.readEof();

  return 0;
}
