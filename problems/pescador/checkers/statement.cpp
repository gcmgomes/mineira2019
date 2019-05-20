#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int m = inf.readInt(1, 100);
  inf.readSpace();
  int n = inf.readInt(2, 1000);
  inf.readEoln();
  for (int i = 0; i < m; i++) {
    inf.readInt(1, 1000);
    inf.readEoln();
  }
  inf.readEof();
}
