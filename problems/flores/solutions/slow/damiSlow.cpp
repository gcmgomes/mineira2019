#include <bits/stdc++.h>
    
#define INF 0x3F3F3F3F
#define DINF 1e+12
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) if(1) cout << #x << " = " << x << endl;
#define debug2(x,y) if(1) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
    
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
    
using namespace std;
    
typedef long long ll;
typedef pair < int, int >  ii;

int N, M, T;
int m[501][501];
int s[501][501][10];

bool kesimoBit(int x, int k){
	return x & (1 << k);
}

int S(int i, int j, int k){
	if(i < 0 || j < 0) return 0;
	return s[i][j][k];
}

bool temTodas(int x, int y, int xx, int yy){
	rep(k, 0, T){
		int q = s[xx][yy][k] - S(x-1, yy, k) - S(xx, y-1, k) + S(x-1, y-1, k);
		if(!q) return false;
	}
	return true;	
}

int main(){

	cin >> N >> M >> T;
	
	rep(i, 0, N)
	rep(j, 0, M){
		scanf("%d", &m[i][j]);
		rep(k, 0, T) s[i][j][k] = 0;
	}

	rep(k, 0, T) s[0][0][k] = kesimoBit(m[0][0], k);
	
	rep(i, 1, N)
	rep(k, 0, T)
	s[i][0][k] = s[i-1][0][k] + kesimoBit(m[i][0], k);
	
	rep(j, 1, M)
	rep(k, 0, T)
	s[0][j][k] = s[0][j-1][k] + kesimoBit(m[0][j], k);
	
	rep(i, 1, N)
	rep(j, 1, M)
	rep(k, 0, T)
	s[i][j][k] = s[i-1][j][k] + s[i][j-1][k] - s[i-1][j-1][k] + kesimoBit(m[i][j], k);
	
	int ans = INF, x, y;
	
	rep(i, 0, N)
	rep(j, 0, M){
		int Q = min(N-i, M-j);
		int parc = INF, xparc, yparc;
		rep(q, 0, Q){
			int xx = i+q;
			int yy = j+q;
			if(temTodas(i, j, xx, yy)){
				parc = q+1;
				xparc = i, yparc = j;
				break;
			}
		}
		if(parc < ans){
			ans = parc;
			x = xparc, y = yparc;
		}
	}
	
	if(ans == INF) cout << "-1\n";
	else cout << ans*ans << "\n" << x << " " << y << "\n";
}