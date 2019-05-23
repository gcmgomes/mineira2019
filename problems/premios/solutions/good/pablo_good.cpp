#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k, i;
    scanf("%d%d",&n,&k);
    vector<pair<int,pair<int,int>>> arr(n);
    for(i=0; i<n; i++) {
        scanf("%d%d%d",&arr[i].second.second,&arr[i].first,&arr[i].second.first);     
        arr[i].second.first *= (-1);
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    printf("%d\n",arr[k-1].second.second);
    return 0;
}
