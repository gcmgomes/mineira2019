#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(1, 1000);
  inf.readSpace();
  int k = inf.readInt(1, n);
  inf.readEoln();

  set<int> sid;
  set<pair<int, int> > repeteco;
  for (int i = 0; i < n; i++) {
    int id, p, t;
    id = inf.readInt(1, n);
    inf.readSpace();
    p = inf.readInt(0, 13);
    inf.readSpace();
    t = inf.readInt(1, 2000);
    inf.readEoln();
    
    repeteco.insert(make_pair(p, t));
    sid.insert(id);
  }

  ensure(repeteco.size() == n);
  ensure(sid.size() == n);

  inf.readEof();

  return 0;
}
