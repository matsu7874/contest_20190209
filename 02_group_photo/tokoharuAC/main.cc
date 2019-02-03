#include <bits/stdc++.h>
using namespace std;

typedef long long LL;


int main() {
    int K, Y, X;
    cin >> K >> Y >> X;
    string result = "yfkpo";
    int cnt = 0;
    for(int y=1; y<=Y; y++) {
        int x = 1;
        if(y%2==0) x=K;
        for(; 1<=x && x <= K;) {
            if(y==Y && x == X) {
                cout << result[cnt%5] << endl;
            }
            cnt++;
            if(y%2==0) x--;
            else x++;
       }
        
        
    }
    
    return 0;
}
