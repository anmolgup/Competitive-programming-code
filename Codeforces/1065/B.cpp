#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    long long cur = 1;
    long long rem = m;
    while(rem > 0){
        long long d = min(cur, rem);
        rem -= d;
        ++cur;
    }
    assert(rem == 0);
    
    long long res = n;
    if(cur > 1) res = n - cur;
    
    cout << max(0ll, n - m * 2) << ' ' << res << endl;
    return 0;
}