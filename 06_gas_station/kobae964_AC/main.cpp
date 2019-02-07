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



int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<PL> yx(n);
  REP(i, 0, n) {
    int y, x;
    cin >> y >> x;
    yx[i] = PI(y, x);
  }
  vector<VI> can(n, VI(n, 0));
  REP(i, 0, n) {
    REP(j, 0, n) {
      ll dx = yx[i].second - yx[j].second;
      ll dy = yx[i].first - yx[j].first;
      if (dx * dx + dy * dy <= d * d) {
        can[i][j] = 1;
      }
    }
  }
  const int inf = 1e8;
  VI dist(n, inf);
  vector<bool> dec(n);
  queue<PI> que;
  que.push(PI(0, 0));
  while (!que.empty()) {
    PI td = que.front(); que.pop();
    int t = td.first;
    int d = td.second;
    if (dec[t]) continue;
    dec[t] = true;
    dist[t] = d;
    REP(i, 0, n) {
      if (can[t][i]) que.push(PI(i, d + 1));
    }
  }
  VI path;
  int cur = n - 1;
  int rem = dist[n - 1];
  while (rem > 0) {
    int nxt = -1;
    REP(i, 0, n) {
      if (can[cur][i] && dist[i] == rem - 1) {
        nxt = i;
        break;
      }
    }
    path.push_back(cur);
    cur = nxt;
    rem--;
  }
  path.push_back(0);
  reverse(path.begin(), path.end());
  REP(i, 0, path.size()) cout << path[i] + 1 << endl;
}
