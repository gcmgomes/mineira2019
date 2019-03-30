#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<pair<string, string>> edges;
    unordered_map<string, int> in_degree;

    std::vector<string> liars;
    string in_degree2, in_degree0;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (a == b) {
            liars.push_back(a);
            if (liars.size() > 1) {
                cerr << "bad input" << endl;
                abort();
            }
        }

        edges.push_back({a, b});
        in_degree[b]++;
        if (in_degree[b] == 2) {
            if (!in_degree2.empty()) {
                cerr << "bad input" << endl;
                abort();
            }                
            in_degree2 = b;
        }
    }

    // whom raffled himself is the liar.
    if (liars.size() == 1) {
        cout << "1\n" << liars[0] << endl;
        return 0;
    }

    // find potential liars.
    for (auto edge : edges) {
        if (in_degree[edge.first] == 0) {
            if (!in_degree0.empty()) {
                cerr << "bad input" << endl;
                abort();
            }
            in_degree0 = edge.first;
        }
        if (edge.second == in_degree2){
            liars.push_back(edge.first);
        } 
    }

    if (liars.size() == 0 || liars.size() > 2) {
        cerr << "bad input" << endl;
        abort();
    }

    // Ensure liar cannot raffled himself.
    if (liars[0] == in_degree0 || liars[1] == in_degree0) {
        cout << "1\n";
        if (liars[0] == in_degree0) cout << liars[1] << endl;
        if (liars[1] == in_degree0) cout << liars[0] << endl;
    } else {
        cout << "2\n";
        sort(liars.begin(), liars.end());
        cout << liars[0] << "\n" << liars[1] << endl;
    }

    return 0;
}
