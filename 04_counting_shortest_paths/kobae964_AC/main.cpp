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

const int N = 10010;

PI dp[N];
vector<PI> p[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  REP(i, 0, m) {
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    p[t].push_back(PI(s, c));
  }
  const int inf = 1.5e9;
  REP(i, 0, n) dp[i] = PI(inf, 0);
  // TODO: #paths overflows.
  dp[0] = PI(0, 1);
  REP(i, 1, n) {
    PI ma(inf, 0);
    for (auto u: p[i]) {
      int d = dp[u.first].first + u.second;
      int cnt = dp[u.first].second;
      if (ma.first == d) {
        ma.second += cnt;
      } else if (ma.first > d) {
        ma.first = d;
        ma.second = cnt;
      }
    }
    dp[i] = ma;
  }
  cout << dp[n - 1].second << endl;
}
