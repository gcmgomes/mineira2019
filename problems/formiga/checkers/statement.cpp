#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  inf.readInt(0, 40);
  inf.readSpace();
  inf.readLong(0, 1000000000000000000ll);
  inf.readEoln();
  inf.readEof();
}
