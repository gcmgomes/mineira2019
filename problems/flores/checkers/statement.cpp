#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  
  int n = inf.readInt(1, 1000);
  inf.readSpace();
  int m = inf.readInt(1, 1000);
  inf.readSpace();
  inf.readInt(1, 10);
  inf.readEoln();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) inf.readSpace();
      inf.readInt(0, 1023);
    }
    inf.readEoln();
  }
  inf.readEof();
}
