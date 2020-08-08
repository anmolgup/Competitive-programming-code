#include <bits/stdc++.h>
using namespace std;
#define int long long 
using ldb = long double;
using pa = pair < int, int >;
#define pb push_back
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MOD = 1e9 + 7, N = 5e5 + 10;
const int LINF = LLONG_MAX;

vector<int>adj[N];
vector<int>tin(N),low(N),visit(N,0);
int timer;
int n, m;
int check;
map<pa,int>mark;
vector<pa>ans;
int dp[N],lvl[N];
void dfs_check_bridge(int v, int p = -1){
    visit[v] = 1;
    tin[v] = low[v] = timer++;
    for(auto to : adj[v]){
        if(to == p){
            continue;
        }
        if(visit[to]){
            low[v] = min(low[v], tin[to]);
        }
        else{
            dfs_check_bridge(to,v);
            low[v] = min(low[v], low[to]);
            if(low[to]>tin[v]){
                check = 1;
            }
        }
    }
}
void dfs(int v, int p = 0){
    lvl[v] = lvl[p] + 1;
    for(auto s : adj[v]){
        if(lvl[s]!=0){
            if(s != p){
                if(lvl[s] > lvl[v]){
                    ans.pb({v+1,s+1});
                }
            }
        }
        else{
            ans.pb({s+1,v+1});
            dfs(s,v);
        }
    }
}

int32_t main() {
    fast();
    cin>>n>>m;
    int i,x,y;
    f(i,0,m){
       cin>>x>>y;
       x--;
       y--;
       adj[x].pb(y);
       adj[y].pb(x);  
    }  
    dfs_check_bridge(0);
    if(check){
        cout << 0 << endl;
        return 0;
    }
    dfs(0);
    for(auto [a,b] : ans){
        cout << a << " " << b << endl;
    }   
    return 0;
}