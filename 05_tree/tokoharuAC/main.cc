#include <bits/stdc++.h>
using namespace std;

typedef long long LL;



int main() {
    int N;
    cin >> N;
    vector<LL> parent(N, -1);
    vector<LL> depth(N, 0);
    vector<LL> cnt(N, 1);
    vector<LL> result(N, 0);
    for(int i=1; i<=N-1; i++) {
        cin >> parent[i];
        depth[i] = 1 + depth[parent[i]];
    }
    for(int i=N-1; i>0; i--) {
        cnt[parent[i]] += cnt[i];
    }
    LL cur = accumulate(depth.begin(), depth.end(), 0LL);
    result[0] = cur;
    for(int i=1; i<=N-1; i++) {
        result[i] = result[parent[i]] - 2*cnt[i] + N;
    }
    for(int i=0; i<N; i++)
        cout << result[i] << endl;
    
    return 0;
}
