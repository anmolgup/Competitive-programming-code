#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;
#define pb push_back
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;
int main() {
    fast_io();
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((d - b) % (__gcd(a, c)) != 0) {
        cout << -1 << endl;
    } else {
        ll x = b;
        ll y = d;
        while (x != y) {
            //debug(x),debug(y);
            if (x < y) {
                x += a;
            } else {
                y += c;
            }
        }
        cout << x << endl;
    }
 
    return 0;
}