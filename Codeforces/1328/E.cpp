#include <bits/stdc++.h>
using namespace std;

#define rep(i,st,en) for(__typeof(en) i=(st)-(st>en); i!=(en)-(st>en); i+=1-2*(st>en))
#define ff first
#define ss second
#define endl '\n'
#define all(v) v.begin(), v.end()
#define corona ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << *it << " = " << a << endl;    err(++it, args...);}
typedef long long ll;
const ll mod = 1e9+7;

int n, timer = 0;
vector<int> adj[200005], hei(200005, 0), par(200005, 0);
vector<int> tin(200005), tout(200005);

void dfs(int v, int p) {
    hei[v] = hei[p]+1;
    tin[v] = ++timer;
    par[v] = p;
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() {
    corona
    int m;  cin>>n>>m;
    rep(i,1,n) {
        int x, y;   cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 1);
    while(m--) {
        int k, mx = 0;  cin>>k;
        vector<int> v(k);
        rep(i,0,k) {
            int x;  cin>>x;
            v[i] = x;
            mx = max(hei[mx], hei[x]) > hei[mx] ? x : mx;
        }
        bool exist = true;
        rep(i,0,k) {
            if(not is_ancestor(par[v[i]], mx))
                exist = false;
        }
        if(exist)   cout<<"YES"<<endl;
        else        cout<<"NO"<<endl;
    }
    return 0;
}