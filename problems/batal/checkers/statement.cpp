#include "testlib.h"
#include <set>

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(1, 1000000);
  inf.readSpace();
  int q = inf.readInt(0, 100000);
  inf.readEoln();
  set<pair<int, int>> filled;
  for (int i = 0; i < q; i++) {
    int x = inf.readInt(1, n);
    inf.readSpace();
    int y = inf.readInt(1, n);
    ensuref(filled.count({x, y}) == 0, "Posição preenchida repetida");
    filled.insert({x, y});
    inf.readEoln();
  }
  inf.readEof();
}
