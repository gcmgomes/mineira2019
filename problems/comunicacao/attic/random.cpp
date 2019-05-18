#include "testlib.h"
#include <iostream>
#include <cassert>

using namespace std;

constexpr int MIN_N = 1;
constexpr int MAX_N = 1.e6;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  registerGen(argc, argv, 1);

  int n = atoi(argv[2]);
  assert(MIN_N <= n and n <= MAX_N);
  
  int m = atoi(argv[3]);
  assert(0 <= m and m <= n);

  int multiple_connections = 0;
  int bad_connections = 0;
  if (argc > 4) {
    multiple_connections = atoi(argv[4]);
    bad_connections = atoi(argv[5]);

    assert(m);
    assert(0 <= multiple_connections);
    assert(0 <= bad_connections);
    assert(m + multiple_connections + bad_connections <= n);
  }

  vector<int> even, odd;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }
  shuffle(even.begin(), even.end());
  
  vector<pair<int, int>> candidate_connections;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      candidate_connections.push_back({i, odd.back()});
      odd.pop_back();
    } else {
      candidate_connections.push_back({i, even.back()});
      even.pop_back();
    }
  }
  shuffle(candidate_connections.begin(), candidate_connections.end());
  candidate_connections.resize(m);

  for (int i = 0; i < multiple_connections; i++) {
    int k = rnd.next(0, m - 1);
    int b = rnd.next(1, n);
    int side = rnd.next(0, 1);
    if (side) {
      candidate_connections.push_back({candidate_connections[k].first, b});
    } else {
      candidate_connections.push_back({b, candidate_connections[k].second});
    }
  }

  for (int i = 0; i < bad_connections; i++) {
    int a, b;
    do {
      a = rnd.next(1, n);
      b = rnd.next(1, n);
    } while (a % 2 == b % 2);
    candidate_connections.push_back({a, b});
  }

  shuffle(candidate_connections.begin(), candidate_connections.end());

  cout << n << ' ' << candidate_connections.size() << '\n';
  for (auto con : candidate_connections) {
    cout << con.first << ' ' << con.second << '\n';
  }
}
