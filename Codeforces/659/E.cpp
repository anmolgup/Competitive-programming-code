#include <bits/stdc++.h>
using namespace std ;
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define MAXN 111111
 
const int INF = 1 << 29 ;
typedef long long ll ;
typedef pair < int , int > pii ;
 
int p[MAXN] ;
vector < int > g[MAXN] ;
bool visited[MAXN]  ,cycle;
 
void dfs(int u) {
    visited[u] = true ;
 
    for(int i =0 ;i<g[u].size() ;i++) {
       int v = g[u][i] ;
       if(!visited[v]){
           p[v] = u ;
           dfs(v) ;
       }
       else if(p[u] != v)cycle = true ;
    }
}
 
int main() {
    int n ,m , ans = 0 , a  , b;
    scanf("%d %d" ,&n ,&m) ;
 
    for(int i = 1 ; i<=m ;i++) {
        scanf("%d %d" ,&a ,&b) ;
        g[a].pb(b) ;
        g[b].pb(a) ;
    }
 
    for(int i= 1;i<=n ;i++) {
        if(!visited[i]) {
            cycle = false ;
            dfs(i) ;
            if(!cycle)ans++ ;
        }
    }
    printf("%d\n" , ans) ;
    return 0 ;
}