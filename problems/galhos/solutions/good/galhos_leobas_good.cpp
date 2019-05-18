#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef vector<vector<int>> graph;

void bfs(const graph &g, vector<int> &tempos, int u, int t){
  queue<int> q;
  
  if (tempos[u] != -1)
    return;
  
  // cout << "deu push em: " << u << " tempos: " << tempos[u] << endl;
  
  q.push(u);
  
  while (!q.empty()){
    int u = q.front();
    q.pop();
    
    tempos[u] = t;
    
    // cout << "marcou tempos[" << u << "] = " << tempos[u] << endl;
    
    for (int i=0; i<g[u].size(); i++){
      int v = g[u][i];
      
      if (tempos[v] == -1)
        q.push(v);
    }
  }
}

void print(const graph &g){
  for (int i=0; i<g.size(); i++){
    cout << i << ": ";
    for (int j=0; j<g[i].size(); j++){
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(){
  
  int n;
  cin >> n;
  
  graph g(n+1);
  
  vector<pair<int, int>> c(n);
  
  for (int i=0; i<n; i++){
    int v = i+1;
    int u;
    cin >> u;
    
    u = u == -1 ? 0 : u;
    
    c[i] = make_pair(u, v);
    g[u].push_back(v);
  }
  
  // print(g);
  
  vector<int> tempos (n+1, -1);
  
  for (int t=1; t<=n; t++){
    // on time @t, the connection from 
    // @v -> @u will be removed
    int i;
    cin >> i;
    
    int u = c[i-1].first;
    int v = c[i-1].second;
    
    // cout << u << ' ' << v << ' ' << t << endl;
    
    bfs(g, tempos, v, t);
  }
  
  for (int i=1; i<=n; i++){
    if(i==n) cout << tempos[i];
    else cout << tempos[i] << ' ';
  }
  cout << endl;
  
  return 0;
}
