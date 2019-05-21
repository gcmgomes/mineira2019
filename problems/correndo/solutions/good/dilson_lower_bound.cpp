#include <iostream>
#include <cmath>
#include <cfenv>

using namespace std;

using ll = long long;

int main() {
  double A, B;
  cin >> A >> B;

  if (A == 2 * B) {
    cout << 3 << endl;
    return 0;
  }

  fesetround(FE_DOWNWARD);
  double angle_cos = B / A;

  fesetround(FE_UPWARD);
  double angle = acos(angle_cos);

  fesetround(FE_DOWNWARD);
  double pi = acos(-1);
  int ans = ceil(pi / angle);
 
  cout << ans << endl; 
}
