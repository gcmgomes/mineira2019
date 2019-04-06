#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define MAX 2500001

struct Node {
    unordered_map<char, int> children;
    bool end_word;

    Node() {
        end_word = false;
    }
};

struct Trie {
    Node nodes[MAX];
    int size = 1;

    int next(int curr, char c) {
        if (nodes[curr].children.find(c) == nodes[curr].children.end()) {
            size++;
            nodes[curr].children[c] = size-1;
            return size-1;
        }
        return nodes[curr].children[c];
    }

    void add_word(const string& word) {
        int curr = 0;
        for (int i = 0; i < word.size(); i++) {
            curr = next(curr, word[i]);
        }
        nodes[curr].end_word = true;
    }
};

Trie trie;

int main(){
    cin.sync_with_stdio(false);
    
    int n;
    cin >> n;

    unordered_map<string, string> translations;

    string a, b;
    getline(cin, a);
    for (int i = 0; i < n; i++) {
        getline(cin, a);
        getline(cin, b);
        translations[a] = b;

        reverse(a.begin(), a.end());
        trie.add_word(a);
    }

    string phrase;
    cin >> phrase;

    vector<int> ans(phrase.size(), -1);
    queue<pair<int, int>> states;
    stack<pair<int, int>> aux;

    states.push(make_pair(0, phrase.size()));

    for (int i = phrase.size()-1; i >= 0; i--) {
        while (!states.empty()) {
            pair<int, int> state = states.front();
            states.pop();
            auto nxt = trie.nodes[state.first].children.find(phrase[i]);
            if (nxt != trie.nodes[state.first].children.end()) {
                aux.push({nxt->second, state.second});
                if (trie.nodes[nxt->second].end_word) {
                    ans[i] = max(ans[i], state.second);
                }
            }
        }
        if (ans[i] != -1) {
            aux.push({0, i});
        }
        while (!aux.empty()) {
            states.push(aux.top());
            aux.pop();
        }
    }

    if (ans[0] == -1) {
        cerr << "Bad input" << endl;
        abort();
    }

    int tocut = ans[0];
    string curr = "";
    for (int i = 0; i < phrase.size(); i++) {
        if (i == tocut) {
            if (tocut != ans[0]) cout << " ";
            cout << translations[curr];
            tocut = ans[i];
            curr = "";
        }
        curr += phrase[i];
    }
    if (tocut != ans[0]) cout << " ";
    cout << translations[curr] << endl;

    return 0;
}
