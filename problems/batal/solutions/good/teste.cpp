#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cost(ll value) {
    if(value<=0) return 0;
    return (value*(value+1))/2;
}

int main() {
    ll n, q, i, x, y, total, left;
    scanf("%lld%lld",&n,&q);
    vector<set<ll>> line(n+5);
    set<ll>::iterator it;
    vector<set<ll>> column(n+5);
 
    for(i=0; i<q; i++) {
        scanf("%lld%lld",&x,&y);
        x--; y--;
        line[x].insert(y);
        column[y].insert(x);
    }

    total = 0;
   
    for(i=0; i<n; i++) {
        left = 0;
        for(it=line[i].begin(); it!=line[i].end(); ++it) {
            total = total+cost(*it-left);
            left = *it+1;   
        } 
        total = total+cost(n-left);
        total -= (n - column[i].size());
        
        left = 0;
        for(it=column[i].begin(); it!=column[i].end(); ++it) {
            total = total+cost(*it-left);
            left = *it+1;
        } 
        total = total+cost(n-left);
    }
    printf("%lld\n",total);
    return 0;
}
