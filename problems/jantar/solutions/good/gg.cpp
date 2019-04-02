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

double PI = acos(-1);

void PrintGood(int n, vector<int>& cycle, vector<int>& is_in_cycle) {
  cout << 1 << endl;
  cout << cycle.size() << endl;
  for (auto& x : cycle) {
    cout << x + 1 << " ";
  }
  cout << endl;
  cout << n - cycle.size() << endl;
  int i = 0;
  while (i < n) {
    if (!is_in_cycle[i]) {
      cout << i + 1 << " ";
    }
    i++;
  }
  cout << endl;
}

void BruteForce(vector<vector<int>>& graph) {
  int n = graph.size();
  int mask = 1 << n, cur = 1;
  while (cur < mask - 1) {
    vector<int> sa(n), side;
    int bit = 1;
    int i = 0;
    while (bit < mask) {
      sa[i] = bit & cur;
      if (sa[i]) {
        side.push_back(i);
      }
      i++;
      bit <<= 1;
    }
    i = 0;
    while (i < n) {
      int c = 0;
      for (auto x : graph[i]) {
        c += (sa[i]) ? sa[x] == 0 : sa[x] != 0;
      }
      if (c > 1) {
        break;
      }
      i++;
    }
    if (i == n) {
      PrintGood(n, side, sa);
      return;
    }
    cur++;
  }
  cout << "0" << endl;
}

void CycleDFS(vector<vector<int>>& graph, vector<int>& cycle,
              vector<int>& cycle_pos, vector<int>& parent) {
  int n = graph.size();
  stack<int> st;
  st.push(0);
  parent[0] = -2;
  while (st.size()) {
    int u = st.top();
    st.pop();
    for (auto x : graph[u]) {
      if (x == parent[u]) {
        continue;
      }
      if (parent[x] == -1) {
        parent[x] = u;
        st.push(x);
      } else {
        cycle.push_back(x);
        cycle_pos[x] = 1;
        int v = u;
        u = parent[parent[x]];
        do {
          cycle.push_back(v);
          cycle_pos[v] = cycle.size();
          v = parent[v];
        } while (v != u);
        parent.assign(n, -1);
        int i = 0;
        parent[cycle[0]] = cycle.back();
        while(i < cycle.size())  {
          parent[cycle[(i+1) % n]] = cycle[i];
          i++;
        }
        return;
      }
    }
  }
}

int ShortenCycle(vector<vector<int>>& graph, vector<int>& cycle,
                 vector<int>& cycle_pos, vector<int>& parent) {
  vector<int> new_cycle;
  int shorter = -1;
  vector<int> cneighs;
  for (auto x : cycle) {
    for (auto y : graph[x]) {
      if (cycle_pos[y] != 0) {
        continue;
      }
      cneighs.clear();
      for (auto z : graph[y]) {
        if (cycle_pos[z] != 0) {
          cneighs.push_back(z);
        }
      }
      if (cneighs.size() > 1) {
        shorter = y;
        break;
      }
    }
    if (cneighs.size() > 1) {
      break;
    }
  }
  if(shorter == -1) {
    return -1;
  }
  int c1 = cneighs[0], c2 = cneighs[1];
  if (cycle_pos[c1] > cycle_pos[c2]) {
    swap(c1, c2);
  }
  if (cycle_pos[c2] - cycle_pos[c1] > cycle.size() / 2) {
    swap(c1, c2);
  }
  while (c2 != c1) {
    if(new_cycle.size() > graph.size()) {
      exit(-1);
    }
    new_cycle.push_back(c2);
    c2 = parent[c2];
  }
  new_cycle.push_back(c1);
  new_cycle.push_back(shorter);
  for (auto x : cycle) {
    cycle_pos[x] = 0;
    parent[x] = -1;
  }
  int i = 0;
  while (i < new_cycle.size()) {
    cycle_pos[new_cycle[i]] = i + 1;
    parent[new_cycle[(i + 1) % new_cycle.size()]] = new_cycle[i];
    i++;
  }
  cycle = new_cycle;
  return shorter;
}

int IncreaseMonochrome(vector<vector<int>>& graph, vector<int>& cycle,
                       vector<int>& is_in_cycle) {

  int i = 0, n = graph.size();
  while(i < n) {
    while(is_in_cycle[i]) {
      i++;
    }
    int c = 0;
    for(auto x : graph[i]) {
      c += is_in_cycle[x] != 0;
    }
    if(c > 1) {
      cycle.push_back(i);
      is_in_cycle[i] = 1;
      return 1;
    }
    i++;
  }
  return 0;
}

void FindDegreeOne(vector<vector<int>>& graph) {
  int n = graph.size();
  int i = 0;
  while(i < n) {
    if(graph[i].size() == 1) {
      break;
    }
    i++;
  }
  vector<int> cycle(1, i), is_in_cycle(n, 0);
  is_in_cycle[i] = 1;
  PrintGood(n, cycle, is_in_cycle);
}

int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  int i = 0;
  while (i < m) {
    int u = 0, v = 0;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
    i++;
  }
  if (n <= 10) {
    BruteForce(graph);
    return 0;
  }
  vector<int> cycle, cycle_pos(n), parent(n, -1);
  CycleDFS(graph, cycle, cycle_pos, parent);
  if (cycle.empty()) {
    FindDegreeOne(graph);
    return 0;
  }
  while (cycle.size() > 4 &&
         ShortenCycle(graph, cycle, cycle_pos, parent) != -1) {
  }
  while (IncreaseMonochrome(graph, cycle, cycle_pos)) {
  }
  PrintGood(n, cycle, cycle_pos);
  return 0;
}
