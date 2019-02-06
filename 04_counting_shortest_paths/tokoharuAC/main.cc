#include <bits/stdc++.h>
using namespace std;

typedef long long LL;



int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<tuple<LL,LL>>> edge(N);
    for(int i=0; i<M; i++) {
        int s, t, c;
        cin >> s >> t >> c;   
        s--;t--;
        edge[s].push_back({t, c});
        edge[t].push_back({s, c});
    }
    vector<LL> dist(N, 1000000000);
    vector<LL> cnt(N, 0);
    dist[0] = 0;
    cnt[0] = 1;
    
    LL MOD = 1000000007;
    priority_queue<tuple<LL,LL>> pq;
    pq.push({0, 0});
    vector<int> used(N, 0);
    while(!pq.empty()) {
        auto vc = pq.top(); pq.pop();
        int v = get<1>(vc);
        int base = -get<0>(vc);
        if(used[v]) continue; 
        used[v] = true;
        if(dist[v] < base) continue;
        for(auto uc : edge[v]) {
            int u = get<0>(uc);
            int c = get<1>(uc);
            if(dist[u] < dist[v] + c) continue;
            if(dist[u] > dist[v] + c) {
                dist[u] = dist[v] + c;
                cnt[u] = 0;
            }
            cnt[u] += cnt[v];
            cnt[u] %= MOD;
            pq.push({-dist[u], u});
        }
    }
    cout << cnt[N-1] << endl;
    
    return 0;
}
