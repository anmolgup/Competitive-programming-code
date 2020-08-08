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
 
char a[N];
char b[N];
 
inline bool read() {
    if (!gets(a)) return false;
    assert(gets(b));
    return true;
}
 
inline void solve() {
    int n = int(strlen(a));
    int m = int(strlen(b));
    reverse(a, a + n);
    reverse(b, b + m);
    while (n < m) a[n++] = '0';
    while (m < n) b[m++] = '0';
    int p = n - 1;
    while (p >= 0 && a[p] == b[p]) p--;
    if (p < 0) puts("=");
    else if (a[p] < b[p]) puts("<");
    else puts(">");
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