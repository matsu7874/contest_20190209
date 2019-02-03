#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL decode(string s) {
    LL ret = 0;
    for(int i=0; i<s.size(); i++) {
        ret *= 2;
        if(s[i] == 'B') ret++;
    }
    return ret;
}

string encode(LL n) {
    vector<int> data;
    while(n != 0) {
        data.push_back(n%2);
        n /= 2;
    }
    reverse(data.begin(), data.end());
    string ret = "";
    for(int i=0; i<data.size(); i++) {
        if(data[i] == 1) ret += "B";
        else ret += "b";
    }
    return ret;
} 


int main() {
    string s;
    string t;
    cin >> s >> t;
    cout << encode(decode(s) + decode(t)) << endl;   
    
    return 0;
}
