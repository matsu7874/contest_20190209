#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

double calc(double x, double y) {
  return sqrt(x * x + y * y);
}

int main() {
  int N, D;
  cin >> N >> D;
  vector<double> x(N), y(N);
  vector<double> dist(N, 1e20);
  vector<int> prev(N, -1);
  for(int i=0; i<N; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> used(N, 0);
  dist[0] = 0;
  for(int z=0; z<N; z++) {
    double minim = 1e20;
    int cand = -1;
    for(int i=0; i<N; i++) {
      if(!used[i] && minim > dist[i]) {
        minim = dist[i];
        cand = i;
      }
    }
    if(cand == -1) break;
    used[cand] = true;
    for(int i=0; i<N; i++) {
      double nd = calc(x[i] - x[cand], y[i] - y[cand]);
      if(nd > D + 1e-10) continue; 
      nd += dist[cand];
      if(nd < dist[i]) {
        prev[i] = cand;
        dist[i] = nd;
      }
    }
  }
  vector<int> ans;
  int cur = N-1;
  while(cur != -1) {
    ans.push_back(cur+1);
    cur = prev[cur];
  }
  reverse(ans.begin(), ans.end());
  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
