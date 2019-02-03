#include <bits/stdc++.h>
using namespace std;

typedef long long LL;


int gcd(int a, int b) {
    return a ? gcd(b%a, a) : b;
}

void solve(int a, int b) {
    int k = gcd(a, b);    
    cout << a/k << " " << b/k << endl;
        
}


int main() {
    int N;
    cin >> N;
    vector<int> S(N), T(N);
    for(int i=0; i<N; i++) cin >> S[i];
    for(int i=0; i<N; i++) cin >> T[i];
    
    int base = S[0] - T[0];
    
    for(int i=0; i<N; i++) {
        solve(S[i] - T[i], base);
    }    
    
    return 0;
}
