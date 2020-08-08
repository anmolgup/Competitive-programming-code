#define DEBUG
// #define FASTIO
 
#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"
 
#ifdef FASTIO
 
#define pr(x) printf("%d", x)
#define ps    printf(" ")
#define endc  printf("\n")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%lf", x)
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define IOS 
 
#endif
 
#ifndef FASTIO
    #define IOS { ios :: sync_with_stdio(false); cin.tie(0); }
#endif
 
#ifdef DEBUG
    #define dbg(s) {s;}
#endif
 
#ifndef DEBUG
    #define dbg(s)
#endif
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}
 
#define int ll
#define i32 int32_t
 
 
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
 
ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 
 
const ll mod = 998244353ll;
 
ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}
 
const int maxn = 1e6 + 7;
 
const ll inf = 1e9 + 7;
 
inline int lg(int x) {
    int dig = 0;
    while (x > 0) {
        dig++; x /= 10ll;
    }
    return dig;
}
 
ll a[maxn][11][2];
ll s[11][11][2];
ll cnt[11];
int pos[20];
ll tp[100];
 
i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    IOS;
    tp[0] = 1ll;
    for (int j = 1; j < 30; j++) {
        tp[j] = (tp[j - 1] * 10ll) % mod;
    }
 
    for (int i = 0; i < 11; i++) for (int j = 0; j < 11; j++) for (int b = 0; b < 2; b++) {
        s[i][j][b] = cnt[i] = 0ll;
    }
 
    int n; cin >> n;
    for (int j = 1; j <= n; j++) {
        int m; cin >> m; cnt[lg(m)]++;
        for (int l = 1; l <= 10; l++) {
            int p = lg(m);
            for (int b = 0; b < 2; b++) {
                if (b == 0) {
                    pos[0] = 0;
                } else {
                    pos[0] = 1;
                }
                for (int i = 1; i < p; i++) {
                    if (b == 0) {
                        if (i > l) {
                            pos[i] = pos[i - 1] + 1;
                        } else {
                            pos[i] = pos[i - 1] + 2;
                        }
                    } else {
                        if (i >= l) {
                            pos[i] = pos[i - 1] + 1;
                        } else {
                            pos[i] = pos[i - 1] + 2;
                        }
                    }
                }
 
                ll val = 0; ll c = m;
                for (int i = 0; i < p; i++) {
                    int d = c % 10ll; c /= 10ll;
                    val = (val + d * tp[pos[i]]) % mod;
                }
 
                a[j][l][b] = val;
 
 
                s[p][l][b] += val; s[p][l][b] %= mod;
            }
        }
    }   
    
    ll ans = 0;
        for (int x = 0; x < 11; x++) {
            for (int y = 0; y < 11; y++) {
                ans += s[x][y][1] * cnt[y]; ans %= mod;
                ans += s[x][y][0] * cnt[y]; ans %= mod;
                ans %= mod;
            }
        }
    
    cout << ans << endl;
}