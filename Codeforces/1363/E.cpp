#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n, cost = 0;
int arr[N], b[N], c[N];
vector<int> g[N];
 
pair<int, int> dfs(int u, int par, int mn)
{
    pair<int, int> a = {0, 0};
    if(b[u] != c[u])
    {
        if(b[u])
            a.first++;
        else
            a.second++;
    }
    for(auto &it:g[u])
    {
        if(it == par)
            continue;
        pair<int, int> p = dfs(it, u, min(mn, arr[u]));
        a.first += p.first;
        a.second += p.second;
    }
    if(arr[u] < mn)
    {
        int take = min(a.first, a.second);
        cost += 2 * take * arr[u];
        a.first -= take;
        a.second -= take;
    }
    return a;
}
 
int32_t main()
{
    IOS;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i] >> b[i] >> c[i];
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    pair<int, int> ans = dfs(1, 0, 2e9);
    if(ans.first || ans.second)
        cout << -1;
    else
        cout << cost;
    return 0;
}