#include <iostream>
#include <vector>
#include <set>
#include <map>

#define MOD 1000000007ll 

using namespace std;


inline long long calc(long long d, bool remove_single){
  if (remove_single)
    return (d*(d+1))/2 - d;
  return (d*(d+1))/2;
}

long long solve(const map<int, set<int>> &m, int n, bool remove_single){

  long long ans = 0;
  
  for (const auto &kv : m){
    int p = 1;
    const auto &v = kv.second;
    // printf("line: %d\n", kv.first);
    
    if (v.empty()){
      // printf("n: %d\n", n);
      ans += calc(n, remove_single);
      continue;
    }
    for (const auto &e : v){
      if (p == e){
        p++;
        continue;
      }
      
      int d = e - p;
      // printf("somou %lld no intervalo [%d - %d] => %d\n", calc(d, remove_single), p, e, d);
      ans += calc(d, remove_single);
      p = e+1;
    }
    
    if (p <= n){
      int d = n - p + 1;
      // printf("*somou %lld no intervalo [%d - %d] => %d\n", calc(d, remove_single), p, n, d);
      ans += calc(d, remove_single);
    }
    
  }
  
  return ans;
}

int main(){
  
  int n, q;
  cin >> n >> q;
  
  map<int, set<int>> line, column;
  
  for (int i=1; i<=n; i++){
    line[i] = set<int>();
    column[i] = set<int>();
  }
  
  for (int i=0; i<q; i++){
    int x, y;
    cin >> x >> y;
    
    line[x].insert(y);
    column[y].insert(x);
  }
  
  long long a = solve(line, n, false);
  long long b = solve(column, n, true);
  
  cout << a+b << endl;
  
  return 0;
}
