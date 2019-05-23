#include <iostream>
#include <tuple>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

struct Rational {
  ll a, b;

  Rational() : a(0), b(1) {}
  
  Rational(ll num, ll den) {
    ll d = gcd(num, den);
    a = num / d;
    b = den / d;
  }

  Rational(ll x) {
    a = x;
    b = 1;
  }

  Rational operator-(const Rational& other) {
    Rational b = other;
    b.a *= -1;
    return *this + b;
  }

  Rational operator*(const Rational& other) {
    return Rational(a * other.a, b * other.b);
  }

  Rational operator+(const Rational& other) {
    ll d = gcd(b, other.b);
    ll den = b / d * other.b;
    ll num = other.b / d * a + b / d * other.a;
    return Rational(num, den);
  }

  void print() {
    if (b == 1) {
      cout << a;
    } else {
      cout << a << '/' << b;
    }
  }
};

ll cost(ll k, ll p) {

  ll mid = 1ll << (k + 1);
  if(p <= mid) {
    return 2ll * (p + (p + 1) / 2ll);
  } else {
    return cost(k, mid) + p - mid + (p -mid + 1) / 2ll ;  
  }
}

pair<ll, ll> g(ll k, ll n) {
  ll ub = (1ll << (k + 2));
  ll round = cost(k, ub);
  if (n >= round) return g(k, n % round);

  ll lb = 0;
  while (lb < ub) {
    ll m = (ub - lb + 1) / 2 + lb;
    ll c = cost(k, m);
    if (c < n) {
      lb = m;
    } else if (c > n) {
      ub = m - 1;
    } else {
      return {m, 0ll};
    }
  }

  return {lb, n - cost(k, lb)};
}


pair<Rational, Rational> getPoint(ll k, ll p) {
  ll mid = 1ll << (k + 1);
  ll x = p <= mid ? (p / 2) : (mid / 2 - (p - mid + 1) / 2);
  ll y = p <= mid ? ((p +1) / 2) : ((mid + 1) / 2 - (p - mid) / 2);

  ll den =  1ll << k;

  return {Rational(x, den), Rational(y, den)};
}



int main() {
  ll k, n;
  cin >> k >> n;

  ll p, r;
  tie(p, r) = g(k, n + n);


  Rational x1, y1;
  tie(x1, y1) = getPoint(k, p);

  Rational x2, y2;
  tie(x2, y2) = getPoint(k, p + 1);

  ll delta = cost(k, p + 1) - cost(k, p);
  Rational lamb(delta - r, delta);

  Rational x = x1 * lamb + (Rational(1) - lamb) * x2;
  Rational y = y1 * lamb + (Rational(1) - lamb) * y2;


  x.print();
  cout << ' ';
  y.print();
  cout << endl;
}
