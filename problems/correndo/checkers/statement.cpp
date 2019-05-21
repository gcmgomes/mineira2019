#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int a = inf.readInt(1, 1000000000);
  inf.readSpace();
  int b = inf.readInt(1, 1000000000);
  ensuref(b < a, "B >= A");
  inf.readEoln();
  inf.readEof();
}
