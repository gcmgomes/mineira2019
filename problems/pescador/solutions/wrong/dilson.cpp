#include <iostream>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    int qi;
    cin >> qi;
    cout << "Peixe " << (i + 1) << ": " << (qi * n) << endl;
  }
}
