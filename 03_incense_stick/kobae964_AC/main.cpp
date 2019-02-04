#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define DEBUGP(val) cerr << #val << "=" << val << "\n"

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
const ll mod = 1e9 + 7;

int gcd(int x, int y) {
  while (y != 0) {
    int r = x % y;
    x = y; y = r;
  }
  return x;
}

string frac(int x, int y) {
  int g = gcd(x, y);
  x /= g; y /= g;
  return to_string(x) + " " + to_string(y);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI s(n);
  VI t(n);
  REP(i, 0, n) cin >> s[i];
  REP(i, 0, n) cin >> t[i];
  REP(i, 0, n) {
    cout << frac(s[i] - t[i], s[0]) << endl;
  }
}
