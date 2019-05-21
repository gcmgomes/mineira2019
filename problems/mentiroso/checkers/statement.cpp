#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);


  int n = inf.readInt(2, 100000);
  inf.readEoln();
  set<string> names;
  map<string, int> in_deg, out_deg;
  string self;
  for (int i = 0; i < n; i++) {
    string a = inf.readToken("[a-z]{1,10}");
    inf.readSpace();
    string b = inf.readToken("[a-z]{1,10}");
    inf.readEoln();

    if (a == b) {
      ensuref(self == "", "Mais de uma pessoa dando presente para si mesma");
      self = a;
    }

    names.insert(a);
    names.insert(b);
    in_deg[b]++;
    out_deg[a]++;
  }
  ensuref(names.size() == n, "Número de nomes distintos é diferente de N");
  for (auto& e : out_deg) {
    ensuref(e.second == 1, "Um pessoa está dando dois presentes");
  }
  int num_deg_two = 0;
  for (auto& e : in_deg) {
    ensuref(e.second < 3, "Mais de um mentiroso, alugém está recebendo mais de dois presentes");
    if (e.second == 2) num_deg_two++;
  }
  ensuref(num_deg_two == 1, "Número errado de mentirosos");
  if (self != "") {
    ensuref(in_deg[self] == 2, "A pessoa que está dando presente para si mesma não é mentirosa");
  }
  inf.readEof();
}
