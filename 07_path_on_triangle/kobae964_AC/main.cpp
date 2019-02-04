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

/*
 * Requirement of headers: vector, queue
 * Verified by: POJ 2135 (http://poj.org/problem?id=2135)
 */
class MinCostFlow {
private:
  struct edge {
    int to, cap, cost, rev; // rev is the position of reverse edge in graph[to]
  };
  typedef std::pair<int, int> P;
  int v; // the number of vertices
  std::vector<std::vector<edge> > graph;
  std::vector<int> h; // potential
  std::vector<int> dist; // minimum distance
  std::vector<int> prevv, preve; // previous vertex and edge
public:
  /* Initializes this solver. v is the number of vertices. */
  MinCostFlow(int v) : v(v), graph(v), h(v), dist(v), prevv(v), preve(v) {}
  /* Initializes this solver with a existing instance. Only graph is copied. */
  MinCostFlow(const MinCostFlow &ano) : v(ano.v), graph(), h(ano.v), dist(ano.v), prevv(ano.v), preve(ano.v) {
    for (int i = 0; i < ano.v; ++i) {
      std::vector<edge> tt;
      for (int j = 0; j < ano.graph[i].size(); ++j) {
	tt.push_back(ano.graph[i][j]);
      }
      graph.push_back(tt);
    }
  }
  /* Adds an edge. */
  void add_edge(int from, int to, int cap, int cost) {
    graph[from].push_back((edge) {to, cap, cost, graph[to].size()});
    graph[to].push_back((edge) {from, 0, -cost, graph[from].size() - 1});
  }
  /* Calcucates the minimum cost flow whose source is s, sink is t, and flow is f. */
  int min_cost_flow(int s, int t, int f) {
    const int inf = 0x3fffffff;
    int res = 0;
    std::fill(h.begin(), h.end(), 0);
    while (f > 0) {
      std::priority_queue<P, std::vector<P>, std::greater<P> > que;
      std::fill(dist.begin(), dist.end(), inf);
      dist[s] = 0;
      que.push(P(0, s));
      while (! que.empty()) {
	P p(que.top()); que.pop();
	int v = p.second;
	if (dist[v] < p.first) {
	  continue;
	}
	for (int i = 0; i < graph[v].size(); ++i) {
	  edge &e = graph[v][i];
	  if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
	    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
	    prevv[e.to] = v;
	    preve[e.to] = i;
	    que.push(P(dist[e.to], e.to));
	  }
	}
      }
      if (dist[t] == inf) {
	return -1; // Cannot add flow anymore
      }
      for (int i = 0; i < v; ++i) {
	h[i] += dist[i];
      }
      // Add flow fully
      int d = f;
      for (int i = t; i != s; i = prevv[i]) {
	d = std::min(d, graph[prevv[i]][preve[i]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int i = t; i != s; i = prevv[i]) {
	edge &e = graph[prevv[i]][preve[i]];
	e.cap -= d;
	graph[i][e.rev].cap += d;
      }
    } // while (f > 0)
    return res;
  }
};


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<VI> c(n, VI(n));
  REP(i, 0, n) {
    REP(j, 0, i + 1) cin >> c[i][j];
  }
  MinCostFlow msf(n * (n + 1) + 1);
  map<PI, int> tbl;
  int cur = 0;
  REP(i, 0, n) {
    REP(j, 0, i + 1) {
      msf.add_edge(2 * cur, 2 * cur + 1, 1, c[i][j]);
      tbl[PI(i, j)] = cur;
      cur += 1;
    }
  }
  int dx[6] = {0, -1, -1, 0, 1, 1};
  int dy[6] = {1, 0, -1, -1, 0, 1};
  REP(i, 0, n) {
    REP(j, 0, i + 1) {
      int th = tbl[PI(i, j)];
      REP(d, 0, 6) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny > nx) continue;
        int targ = tbl[PI(nx, ny)];
        msf.add_edge(2 * th + 1, 2 * targ, 1, 0);
      }
    }
  }
  msf.add_edge(2 * tbl[PI(0, 0)] + 1, n * (n + 1), 1, 0);
  msf.add_edge(2 * tbl[PI(n - 1, n - 1)] + 1, n * (n + 1), 1, 0);
  cout << msf.min_cost_flow(2 * tbl[PI(n - 1, 0)] + 1, n * (n + 1), 2) << endl;
}
