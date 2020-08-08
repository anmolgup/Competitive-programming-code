#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main() {
    int n;
    cin >> n;
    vector<lld> V(n);
    lld ans = 0;
    for (int i = 0; i < n; i++) cin >> V[i];
    if (n == 1) cout << V[0] << endl;
    else if(n == 2) cout << (V[0]|V[1]) << endl;
    else {
        for (int i = 0; i< n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    ans = max(V[i]|V[j]|V[k], ans);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}