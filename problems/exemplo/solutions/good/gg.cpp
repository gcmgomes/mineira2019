#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int INF = std::numeric_limits<int>().max();
double INFD = std::numeric_limits<double>().max();

double PI = acos(-1);

vector<long long > pows(15);

void init() {
  int i = 1;
  pows[0] = 1;
  while(i < pows.size()) {
    pows[i] = pows[i-1] * 10;
    i++;
  }
}

int main() {
  init();
  ios::sync_with_stdio(false);
  long long n = 0, m = 0;
  cin >> n >> m;
  if(n % m == 0) {
    cout << n << endl;
    return 0;
  }
  int dm = upper_bound(pows.begin(), pows.end(), m) - pows.begin();
  int dn = upper_bound(pows.begin(), pows.end(), n) - pows.begin();
  int pos = dm-1;
  int i = 0;
  long long best = std::numeric_limits<long long>().max(); 
  while(i <= dm) {
    int up = 0;
    while(up < pows[i]) {
      long long n2 = up * pows[dn] + n;
      n2 *= pows[dm - i];
      int down = 0;
      while(down < pows[dm - i]) {
        if((n2 + down) % m == 0) {
          best = min(best, n2 + down);
        }
        down++;
      }
      up++;
    }
    i++;
  }
  cout << best << endl;
  return 0;
}
