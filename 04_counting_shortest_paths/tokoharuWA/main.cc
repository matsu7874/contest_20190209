#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<PII>> edge(N);
    for(int i=0; i<M; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        s--;t--;
        edge[s].push_back(PII(t, c));
        
    }
    vector<PII> dp(N, PII(1000000000, 0));
    dp[0] = PII(0, 1);
    for(int i=0; i<N; i++) {
        if(dp[i].second == 0) continue;
        for(auto vc: edge[i]) {
            int v = vc.first;
            int c = vc.second;
            LL cost = dp[i].first + c;
            if(cost < dp[v].first) {
                dp[v].first = cost;
                dp[v].second = 0;
            }
            if(dp[v].first == cost) {
                dp[v].second += dp[i].second;
            }
        }
    }
    cout << dp[N-1].second << endl;
    
    return 0;
}
