#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

map<string,set<string>> graph;
map<string,set<string>> inverted;
map<string,set<string>>::iterator it;
set<string> solution;
set<string>::iterator ita;


int main() {
    ios_base::sync_with_stdio(false);
    ll n, i;         
    string nodeA, nodeB;
   
    cin >> n;
    for(i=0; i<n; i++) {
        cin >> nodeA >> nodeB;
        if(nodeA==nodeB) {
            cout << 1 << endl;
            cout << nodeA << endl;
            return 0;
        }
        graph[nodeA].insert(nodeB);        
        inverted[nodeB].insert(nodeA);
    }

    for(it=inverted.begin(); it!=inverted.end(); ++it) {
        if(inverted[it->first].size()>1) {
            for(ita=inverted[it->first].begin(); ita!=inverted[it->first].end(); ita++) {
                if(inverted[*ita].size()>0) solution.insert(*ita);
            }
        }                  
    }
    
    cout << solution.size() << endl;
    for(ita=solution.begin(); ita!=solution.end(); ++ita) {
        cout << *ita << endl;
    }

    return 0;
}
