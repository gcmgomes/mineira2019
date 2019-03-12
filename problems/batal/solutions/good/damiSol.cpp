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

const int MAXN = 1000010;
const int mod = 1000000007;

vector<int> lista[2*MAXN];

ll calc(ll x){
	return (x*(x+1))/2;
}

int main(){

	int N, Q;
	cin >> N >> Q;
	
	rep(i, 0, Q){
		int x, y;
		scanf("%d%d", &x, &y);
		lista[x].pb(y);
		lista[y+N].pb(x);
	}
	
	ll ans = 0;
	
	for(int i=1; i<=2*N; i++){
		int sz = lista[i].size();
		if(!sz){
			ans += calc(N);
			continue;
		}
		int last = 0;
		sort(all(lista[i]));
		for(int j=0; j<sz; j++){
			int curr = lista[i][j];
			ll blockSize = curr-last-1;
			ans = (ans + calc(blockSize)) % mod;
			last = curr;
		}
		ans = (ans + calc(N-last)) % mod;
	}
	
	int emptyCells = N*N-Q; 
	cout << ans-emptyCells << "\n";
	
}
