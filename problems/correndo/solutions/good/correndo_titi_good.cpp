#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  long double a, b;
  
  cin >> a >> b;
 
  long double resp = ceil(acos(-1)/acos(a/b));
  cout << std::fixed << std::setprecision(0) << resp << endl;

  return 0;
}
