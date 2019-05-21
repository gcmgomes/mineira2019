#include "testlib.h"

using namespace std;


void dfs(vector<vector<int>>& g, vector<bool>& vis, int a) {
  vis[a] = true;
  for (int b : g[a]) {
    if (not vis[b]) dfs(g, vis, b);
  }
}

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(1, 200000);
  inf.readEoln();
  vector<vector<int>> g(n);
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (i) inf.readSpace();
    int p = inf.readInt(-1, n);
    ensuref(p != 0, "P_i = 0");
    if (p == -1) {
      ensuref(root == -1, "Mais de uma raiz");
      root = i;
    } else {
      g[p - 1].push_back(i);
    }
  }
  inf.readEoln();
  ensuref(root != -1, "Nenhuma raiz");

  vector<bool> vis(n);
  dfs(g, vis, root);
  for (int i = 0; i < n; i++) {
    ensuref(vis[i], "Desconectado");
  }

  vector<bool> used(n);
  for (int i = 0; i < n; i++) {
    if (i) inf.readSpace();
    int b = inf.readInt(1, n);
    b--;
    ensuref(not used[b], "B não é permutação");
    used[b] = true;
  }
  inf.readEoln();

  inf.readEof();
}
