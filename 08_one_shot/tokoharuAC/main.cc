#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

template <class VAL, class TIME>
struct SlideMin {
  const VAL INF = 1LL << 60;  // to be set appropriately
  const TIME nul = -1;        // to be set appropriately

  deque<pair<VAL, TIME> > deq;
  SlideMin() {}

  // get minimum
  pair<VAL, TIME> get() {
    if (deq.empty()) return make_pair(INF, nul);
    return deq.front();
  }

  // push (v, t), "t is non-decreasing" is necessary
  void push(VAL v, TIME t) {
    while (!deq.empty() && deq.back().first >= v) deq.pop_back();
    deq.emplace_back(v, t);
  }

  // pop "< t", "t it non-decreasing" is necessary
  void pop(TIME t) {
    while (!deq.empty() && deq.front().second < t) deq.pop_front();
  }
};



int main() {
    SlideMin<LL, LL> data;
    int N, K;   
    cin >> N >> K;
    LL ans = 0;
    vector<LL> F(N);
    for(int i=0; i<N; i++) cin >> F[i];
    for(int j=0; j<min(K,N); j++) data.push(-F[j], j);
    for(int i=0; i<N; i++) {
       LL b;
       cin >> b;
       if(i+K<=N-1) data.push(-F[i+K], i+K);
       data.pop(i-K);
       LL tmp = data.get().first;
       ans = max(ans, b - tmp);
    }
    cout << ans << endl;
    
    
    
    
    return 0;
}
