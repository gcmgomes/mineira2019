#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

int v[1001][1001];

inline int op(const int value, const int shift){
  int v = (value & (1 << shift));
  return (v ? 1 : 0);
}

vector<vector<int>> calc(int n, int m, int shift){
  vector<vector<int>> d(n, vector<int>(m, 0));
  
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (i == 0 && j == 0){
        d[i][j] = op(v[i][j], shift);
      }
      else if (i == 0){
        d[i][j] = d[i][j-1] + op(v[i][j], shift);
      }
      else if (j == 0){
        d[i][j] = d[i-1][j] + op(v[i][j], shift);
      }
      else {
        d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + op(v[i][j], shift);
      }
    }
  }
  
  return d;
}

int find_min(const vector<vector<int>> &d, int n, int m, int i, int j){
  int l = 0;
  while (i+l < n && j+l < m){
    int diag = (i-1 >= 0 && j-1 >= 0) ? d[i-1][j-1] : 0;
    int up = (i-1 >= 0) ? d[i-1][j+l] : 0;
    int down = (j-1 >= 0) ? d[i+l][j-1] : 0;
    if(d[i+l][j+l] - up - down + diag){
      return l;
    } 
    
    l++;
  }
  
  return -1;
}

void solve(int n, int m, int t){
  vector<vector<int>> ds[10];

  for (int shift=0; shift<t; shift++){
    auto d = calc(n, m, shift);
    ds[shift] = d;
  }
  
  int max_size = 0x3f3f3f3f;
  int i_ans, j_ans;
  
  for(int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      int min_len = -1;
      for (int shift=0; shift<t; shift++){
        int len = find_min(ds[shift], n, m, i, j);
        
        if (len == -1){
          min_len = 0x3f3f3f3f;
          break;
        }
        
        min_len = max(min_len, len);
      }
      
      if (min_len < max_size){
        i_ans = i;
        j_ans = j;
        max_size = min(max_size, min_len);
      }
    }
  }
  
  if (max_size == 0x3f3f3f3f){
    cout << "-1\n";
  }
  else {
    cout << (max_size+1)*(max_size+1) << "\n" << i_ans << ' ' << j_ans << "\n";
  }
}


int main(){
  ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m >> t;
  
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> v[i][j];
    }
  }
  
  solve(n, m, t);
  
  return 0;
}
