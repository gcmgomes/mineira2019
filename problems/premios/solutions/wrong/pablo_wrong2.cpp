#include<bits/stdc++.h>

using namespace std;

int main() {  
    int n, k, i, trash;
    scanf("%d%d",&n,&k);
    vector<pair<int,int>> arr(n); 
    for(i=0; i<n; i++) {
        scanf("%d%d%d",&arr[i].second,&trash,&arr[i].first); 
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    printf("%d\n",arr[k-1].second);
    return 0;
}
