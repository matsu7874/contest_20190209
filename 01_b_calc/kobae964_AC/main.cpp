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

ll to_ll(string s) {
  ll c = 0;
  for (char ch: s) {
    c *= 2;
    if (ch == 'B') c += 1;
  }
  return c;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  // Assuming |s|, |t| <= 50.
  assert(s.size() <= 50);
  assert(t.size() <= 50);
  ll value = to_ll(s) + to_ll(t);
  string ans;
  while (value > 0) {
    if (value % 2) ans += 'B';
    else ans += 'b';
    value /= 2;
  }
  if (ans.size() == 0) ans = 'b';
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
