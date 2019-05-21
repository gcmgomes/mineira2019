#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

int main() {
  double A, B;
  cin >> A >> B;
  int ans = ceil(M_PI / asin(sqrt(A * A - B * B) / A));
  cout << ans << endl; 
}
