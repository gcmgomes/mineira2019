#include <bits/stdc++.h>


using namespace std;

using ll = long long;

#define db(x) cerr << #x << " == " << (x) << endl;
//#define db(x)

uint64_t getSeed() {
   auto ptr = new char;
   delete ptr;
   return (uint64_t) ptr + 
          chrono::high_resolution_clock::now().time_since_epoch().count();
}

mt19937 rnd(getSeed());

ll rndVal(uint64_t a, uint64_t b) {
   return uniform_int_distribution<uint64_t>(a, b)(rnd);
}

constexpr uint64_t MOD = (1ull << 61) - 1; 

inline uint64_t mod(uint64_t x) {
   x++;
   x = (x & MOD) + (x >> 61);
   x = (x & MOD) + (x >> 61);
   return x - 1;
}

uint64_t mulmod(const uint64_t a, const uint64_t b) {
   uint64_t ha = a >> 32, la = uint32_t(a), hb = b >> 32, lb = uint32_t(b);
   uint64_t h = ha * hb, m = ha * lb + la * hb, l = la * lb;
   return mod((l & MOD) + (l >> 61) + (m >> 29) + (m << 35 >> 3) + (h << 3));
}

struct Hash{
   vector<uint64_t> h;
   vector<uint64_t> p;

   void build(const string& s, const uint64_t base) {
      int n = s.size();
      h.resize(n + 1);
      p.resize(n + 1);
      h[0] = 1;
      p[0] = 1;
      for (int i = 0; i < n; i++) {
         h[i + 1] = mod(mulmod(h[i], base) + s[i] + 130);
         p[i + 1] = mulmod(p[i], base);
      }
   }

   void build(const string& s) {
      build(s, rndVal(258, MOD - 1));
   }

   uint64_t query(int l, int r) {
      return mod(h[r + 1] + MOD - mulmod(h[l], p[r - l + 1]));
   }
};

uint64_t bf(const string& s, int l, int r) {
   uint64_t h = 0;
   for (int i = l; i <= r; i++) {
      h = mod(mulmod(h, 12345) + s[i] + 130);
   }
   return h;
}

int n, m;
Hash h;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  uint64_t base = rndVal(258, MOD - 1);


  unordered_map<uint64_t, string> trans;
  
  
  cin >> n;
  while (cin.peek() == '\n') cin.get();
  int max_size = 0;
  for (int i = 0; i < n; i++) {
    string word;
    getline(cin, word);
    h.build(word, base);
    auto word_hash = h.query(0, word.size() - 1);

    string meaning;
    getline(cin, meaning);
    trans[word_hash] = meaning;
    max_size = max(max_size, int(word.size()));
    
  }

  string s;
  getline(cin, s);
  h.build(s, base);
  

  vector<int> dp(s.size() + 1);
  dp[s.size()] = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    for (int j = i; j < s.size() and j - i + 1 <= max_size; j++) {
      if (not dp[j + 1]) continue;
      auto q = h.query(i, j);
      auto it = trans.find(q);
      if (it == trans.end()) continue;

      dp[i] = j - i + 1;
    }
  }

  
  for (int p = 0; p < s.size(); p += dp[p]) {
    auto q = h.query(p, p + dp[p] - 1);
    if (p) cout << ' ';
    cout << trans[q];
  }
  cout << endl;
}
