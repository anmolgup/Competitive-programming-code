#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<ll> dp(n + 1, INF);
    vector<int> parent(n);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= min(6, i); j++) {
            const ll val = dp[i - j] + v[i - 1].first - v[i - j].first;
            if (dp[i] > val) {
                dp[i] = val, parent[i - 1] = j;
            }
        }
    }
 
    // work on colors now...
    // gods, it's 2019, who asks to reconstruct dp anymore
    vector<int> color(n);
    int cur = 1;
    for (int i = n - 1; i >= 0; cur++) {
        for (int j = i; j > i - parent[i]; j--) {
            color[v[j].second] = cur;
        }
        i -= parent[i];
    }
 
    cout << dp.back() << ' ' << (cur - 1) << '\n';
    for (int c : color) cout << c << ' ';
    cout << '\n';
}