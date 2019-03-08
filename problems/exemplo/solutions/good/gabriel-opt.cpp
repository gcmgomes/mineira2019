#include <bits/stdc++.h>

using namespace std;

long long doit(long long n, int m) {
  set<pair<long long, long long>> s;

  // We know we never need to add more digits than m has. We use this to prune
  // the search.
  long long power_m = 10, power_n = 10;
  while (power_m < m) power_m *= 10;
  while (power_n < n) power_n *= 10;

  long long upper_limit = power_n * power_m;

  s.insert(make_pair(power_n, n));
  long long ans = numeric_limits<long long>::max();
  bool found_ans = false;

  while (s.size()) {
    auto next = *s.begin();
    s.erase(s.begin());
    long long nextp = next.first, nextn = next.second;

    if (nextn % m == 0) {
      ans = min(ans, nextn);
      break;
    }

    if (nextp == upper_limit)
      continue;

    // Add left.
    for (int i = 0; i <= 9; i++) {
      pair<long long, long long> addl{nextp * 10, nextn + (nextp * i)};
      if (addl.second % m == 0) {
        found_ans = true;
        ans = min(ans, addl.second);
      }
      if (!found_ans && !s.count(addl)) {
        s.insert(addl);
      }
    }

    // Add right.
    for (int i = 0; i <= 9; i++) {
      pair<long long, long long> addr{nextp * 10, 10*nextn + i};
      if (addr.second % m == 0) {
        found_ans = true;
        ans = min(ans, addr.second);
      }
      if (!found_ans && !s.count(addr)) {
        s.insert(addr);
      }
    }
  }

  return ans;
}

int main() {
  long long n, m;
  cin >> n >> m;

  cout << doit(n, m) << endl;

  return 0;
}
