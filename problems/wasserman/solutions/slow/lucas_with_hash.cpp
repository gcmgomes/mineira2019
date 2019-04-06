#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define MAXS 50001
#define MAXP 1000001
#define MAXL 51

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;

ullong hashp[MAXP];
ullong hasht[MAXS];
ullong powb[MAXL];

const ullong B = 307; 
const ullong C = 5381;

void precomp(){
    powb[0] = 1;
    for (int i = 1; i < MAXL; ++i) 
        powb[i] = powb[i-1]*B;
}

void computeHashWords(const string &word, int i){
    hasht[i] = C;
    for (int j = 1; j <= word.length(); ++j){
        hasht[i] = hasht[i] * B + word[j-1];
    }
}

void computeHashPhrase(const string &phrase){
    hashp[0] = C;
    for (int j = 1; j <= phrase.length(); ++j){
        hashp[j] = hashp[j-1] * B + phrase[j-1];
    }
}

bool comp(const pair<string, string>& a, const pair<string, string>& b) {
    return a.first.size() > b.first.size();
}

string phrase;
vector<pair<string, string>> translations;

bool match(const string& phrase, int i, int j) {
    int size = translations[j].first.size();
    ullong subhashp = hashp[i+size] - hashp[i] * powb[size];
    subhashp += C * powb[size];
    return subhashp == hasht[j];
}

int solve(vector<int> &ans, int i) {
    if (ans[i] == -1) {
        for (int j = 0; j < translations.size(); j++) {
            if (match(phrase, i, j)) {
                int k = i + translations[j].first.size();
                if (k == phrase.size() || solve(ans, k) != -1) {
                    ans[i] = j;
                    break;
                }
            }
        }
    }
    return ans[i];
}

int main(){
    cin.sync_with_stdio(false);
    
    int n;
    cin >> n;

    string a, b;
    getline(cin, a);
    for (int i = 0; i < n; i++) {
        getline(cin, a);
        getline(cin, b);
        translations.push_back({a, b});
    }

    sort(translations.begin(), translations.end(), comp);

    cin >> phrase;

    precomp();
    for (auto i = 0; i < translations.size(); i++) {
        computeHashWords(translations[i].first, i);
    }
    computeHashPhrase(phrase);

    vector<int> ans(phrase.size(), -1);

    solve(ans, 0);

    if (ans[0] == -1) {
        cerr << "Bad input" << endl;
        abort();
    }

    int last = 0;
    while (last < phrase.size()) {
        if (last != 0) cout << " ";
        cout << translations[ans[last]].second;
        last = last + translations[ans[last]].first.size();
    }
    cout << endl;

    return 0;
}
