#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
typedef long long int ll;
typedef long double ld;

int n, m, t;
int M[501][501];
int MM[10][501][501];

inline bool valid(int i, int j) {
  if(i < 0 || j < 0) return false;
  if(i >= n || j >= m) return false;
  return true;
}

inline int vai(int i, int j, int tipo) {
  if(!valid(i, j)) return 0;
  return MM[tipo][i][j];
}

int get(int i, int j, int k, int tipo) {
  return vai(i+k, j+k, tipo) -
         vai(i+k, j-1, tipo) - 
         vai(i-1, j+k, tipo) + 
         vai(i-1, j-1, tipo);
}

int bb(int i, int j) {
  int l = 0, r = min(n-1-i, m-1-j);

  while(l < r) {
    int mid = (l+r)/2;

    bool deu = true;
    for(int tipo = 0; tipo < t; tipo++) {
      if (get(i, j, mid, tipo) == 0) {
        deu = false;
        break;
      }
    }

    if (deu) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  
  bool deu = true;
  for(int tipo = 0; tipo < t; tipo++) {
    if (get(i, j, l, tipo) == 0) {
      deu = false;
      break;
    }
  }

  if(!deu) return INF;
  return l;
}

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> M[i][j];
    }
  }
  
  for (int k = 0; k < t; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((1<<k)&M[i][j]) MM[k][i][j] = 1;
        if (i != 0) {
          MM[k][i][j] += MM[k][i-1][j];
        }
        if (j != 0) {
          MM[k][i][j] += MM[k][i][j-1];
        }
        if(i != 0 && j != 0) {
          MM[k][i][j] -= MM[k][i-1][j-1];
        }
      }
    }
  }
  
  int resp = INF;
  int ri=-1, rj=-1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int hue = bb(i, j);
      if(hue < resp) {
        resp = hue;
        ri = i;
        rj = j;
      }
    }
  }
  if (resp == INF) {
    cout << "-1\n";
  } else {
    resp++;
    cout << resp*resp << endl;
    cout << ri << " " << rj << endl;
  }

  return 0; 
}
