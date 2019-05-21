#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

int main() {
  double A, B;
  cin >> A >> B;
  int ans = ceil(M_PI / acos(B / A));
  cout << ans << endl; 
}
