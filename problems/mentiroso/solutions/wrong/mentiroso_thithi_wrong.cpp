#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int ll;
typedef long double ld;

#define MAXN 100001

vector<int> tgraph[MAXN];
int indegree[MAXN];

int main() {

  int n, cnt=0;
  string a, b;
  map<string, int> m;

  // Criei esse map pq o statement nao fala o tamanho maximo da string.
  map<int, string> names;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    
    if (m.find(a) == m.end()) {
      m[a] = cnt;
      names[cnt] = a;
      cnt++;
    }
    if (m.find(b) == m.end()) {
      m[b] = cnt;
      names[cnt] = b;
      cnt++;
    }

    indegree[m[b]]++;
    tgraph[m[b]].pb(m[a]);
  }
  
  set<string> ss;
  for(int i = 0; i < n; i++) {
    if(indegree[i] > 1) {
      for(const int hue : tgraph[i]) {
        ss.insert(names[hue]);
      }
    }
  }

  cout << ss.size() << endl;
  for(const string& s : ss) {
    cout << s << endl;
  }  
  
  return 0;
}
