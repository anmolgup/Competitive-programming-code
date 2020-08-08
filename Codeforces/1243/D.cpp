#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 
 
int deg[N];
vector<array<int,2>> edge;
vector<int> g[N];
set<int> vis;
int cost = -1;
int n,m;
 
void dfs(int u){
   vector<int> tt;
   for(auto &v : vis){
      if(!binary_search(all(g[u]),v)){
         tt.pb(v);
      }
   }
   for(auto &v : tt){
      vis.erase(v);
   }
   for(auto &v : tt){
      dfs(v);
   }
}
 
int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   f(i,1,n+1){
      vis.insert(i);
     deg[i] = n-1;
   }
   edge.resize(m);
   f(i,0,m){
      cin >> edge[i][0] >> edge[i][1]; 
      g[edge[i][0]].pb(edge[i][1]);
      g[edge[i][1]].pb(edge[i][0]);   
   }
   f(i,1,n+1){
      sort(all(g[i]));
   }
   f(i,1,n+1){
      if(vis.find(i)!=vis.end()){
         vis.erase(i);
         dfs(i);
         cost++;
      }
   }
   cout << cost << '\n';
   return 0;
}