#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b))/2)
#define INF (1e9 + 7)
 
ll t, u, v, n, k;
const int N = 200;
ll DP [N][N][2];
int main(){
        csl;
        cin >> t;
        while(t--){
                cin >> u >> n >> k;
                rep (i, n)
                        rep (j, k + 1)
                                rep (c, 2)
                                        DP[i][j][c] = 0;
                DP[0][0][1] = DP[0][0][0] = 1;
                reps (i, 1, n)
                        rep (j, k + 1) {
                                DP[i][j][0] = DP[i - 1][j][0] + DP[i - 1][j][1];
                                if(j > 0)
                                        DP[i][j][1] = DP[i - 1][j - 1][1];
                                DP[i][j][1] += DP[i - 1][j][0];
                }
                cout << u << " " << DP[n - 1][k][1] + DP[n - 1][k][0] << '\n';
        }
    return 0;
