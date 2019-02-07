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
typedef pair<int, ll> PIL;
const ll mod = 1e9 + 7;

const int N = 10010;

PIL dp[N];
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
    p[s].push_back(PI(t, c));
  }
  const int inf = 1.5e9;
  REP(i, 0, n) dp[i] = PI(inf, 0);
  priority_queue<PI, vector<PI>, greater<PI> > que;
  que.push(PI(0, 0));
  dp[0] = PI(0, 1);
  while (!que.empty()) {
    PI wv = que.top(); que.pop();
    int w = wv.first;
    int v = wv.second;
    // cerr << "seen " << w << " " << v << endl;
    if (w > dp[v].first) { continue; }
    for (auto u: p[v]) {
      int to = u.first;
      int cost = u.second;
      int d = dp[v].first + cost;
      ll cnt = dp[v].second;
      if (dp[to].first == d) {
        // cerr << "UPD " << v << " " << cnt << endl;
        dp[to].second += cnt;
        dp[to].second %= mod;
      } else if (dp[to].first > d) {
        // cerr << to << " " << d << " " << dp[to].first << " " << dp[to].second << endl;
        dp[to].first = d;
        dp[to].second = cnt;
        que.push(PI(d, to));
      }
    }
  }
  REP(i, 0, n) cerr << " " << dp[i].first << " " << dp[i].second << endl;
  cout << dp[n - 1].second << endl;
}
