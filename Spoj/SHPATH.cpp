#include <bits/stdc++.h>
using namespace std ;
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define MAXN 11111
 
const int INF = 1 << 29 ;
typedef long long ll ;
typedef pair < int , int > pii ;
 
int dijkstra(vector < vector <pii > > &g , int start , int target) {
    vector < int > d(g.size()+1 , INT_MAX) ;
    d[start] = 0 ;
    set < pii > city ;
    city.insert(mp(0,start)) ;
 
    while(!city.empty()) {
        int where = city.begin()->second ;
        if(where == target) return d[target] ;
        city.erase(city.begin()) ;
 
        for(int i = 0 ;i<g[where].size() ; i++){
            pii v = g[where][i] ;
 
            if(d[where]+ v.second < d[v.first]){
                city.erase(mp(d[v.first] , v.first)) ;
                d[v.first] = d[where] + v.second ;
                city.insert(mp(d[v.first] , v.first)) ;
            }
        }
    }
    return INT_MAX ;
}
 
int main() {
    int t  , n , c, idx  , w ;
    string s1 ,s2 ;
    scanf("%d" ,&t) ;
 
    while(t--) {
        scanf("%d" ,&n) ;
        vector < vector < pii > > g(n+2); 
        map < string , int > m ;
        for(int i = 1 ; i<=n ;i++) {
            cin >> s1 ;
            m[s1] = i ;
            scanf("%d" ,&c) ;
            for(int j = 1 ;j<= c ;j++) {
                scanf("%d %d", &idx ,&w) ;
                g[i].pb(mp(idx ,w)) ;
            }
        }
 
        scanf("%d" ,&idx) ;
        for(int i = 1 ;i<=idx ;i++) {
            cin >> s1 >> s2 ;
            printf("%d\n" ,dijkstra(g , m[s1], m[s2])) ;
        }
    }
    return 0 ;
}
