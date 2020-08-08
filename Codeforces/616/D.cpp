#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
const int N = 1200300;
 
int n, k;
int a[N];
 
inline bool read() {
    if (!(cin >> n >> k)) return false;
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    return true;
}
 
int cur;
int cnt[N];
 
inline void add(int x) {
    if (++cnt[x] == 1) cur++;
}
 
inline void rem(int x) {
    if (--cnt[x] == 0) cur--;
}
 
inline void solve() {
    cur = 0;
    memset(cnt, 0, sizeof(cnt));
 
    int al = -1, ar = -1;
    int p = 0;
    forn(i, n) {
        while (p < n) {
            add(a[p]);
            if (cur > k) {
                rem(a[p]);
                break;
            }
            p++;
        }
        if (ar - al < p - i) al = i, ar = p;
        rem(a[i]);
        //cerr << i << ' ' << p << endl;
    }
    assert(al != -1);
    cout << al + 1 << ' ' << ar << endl;
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        solve();
        //break;
    }
   
    return 0;
}