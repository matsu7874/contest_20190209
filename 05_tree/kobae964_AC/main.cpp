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
typedef pair<ll, ll> PL;
const ll mod = 1e9 + 7;

const int N = 100100;
int p[N];
VI ch[N];
PL dist[N];
ll ans[N];

PL dfs1(int v) {
  ll sum = 0;
  ll cnt = 1;
  for (int w: ch[v]) {
    PL sub = dfs1(w);
    sum += sub.first + sub.second;
    cnt += sub.second;
  }
  return dist[v] = PL(sum, cnt);
}

void dfs2(int v, ll sum, ll cnt) {
  ans[v] = sum + dist[v].first;
  //cerr << v << " " << sum << " " << cnt << endl;
  for (int w: ch[v]) {
    ll other_cnt = dist[v].second - dist[w].second;
    ll other_sum = dist[v].first - dist[w].first - dist[w].second;
    dfs2(w, sum + other_sum + other_cnt + cnt, cnt + other_cnt);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  REP(i, 0, n - 1) {
    cin >> p[i + 1];
    ch[p[i + 1]].push_back(i + 1);
  }
  dfs1(0);
  dfs2(0, 0, 0);
  //REP(i, 0, n) cerr << " (" << dist[i].first << " " << dist[i].second << ")";
  //cerr << endl;
  REP(i, 0, n) cout << ans[i] << endl;
}
