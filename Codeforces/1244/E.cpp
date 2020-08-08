#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

template < typename T > using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

#ifdef HOME
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    int len = comma - names;
    for (int i = 0; i < len; ++i) {
        cout << names[i];
    }
    cout <<  " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;
typedef vector < ll > vll;
typedef vector < int > vi;
typedef complex < double > com;

#define eb emplace_back
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique_sort(x) (sort(x.begin(), x.end()), x.resize(distance(x.begin(), unique(x.begin(), x.end()))))
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll LINF = LLONG_MAX, base = 1e9, MOD = 1e9 + 7, N = 1e5 + 5, M = 1e3 + 5, LG = 20;
const int INF = INT_MAX;
const db PI = acos(-1), EPS = 1 / db(1e6);
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

ll n, k, a[N], pre[N], suf[N];

bool check(ll x) {
    for (int i = 1; i <= n; ++i) {
        ll tot = a[i] * i - pre[i]; // Considering a[i] as min element in final array
        ll idx = upper_bound(a, a + n + 1, a[i] + x) - a;
        tot += suf[idx] - (a[i] + x) * (n - idx + 1);
        if (tot <= k) {
            return true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll tot = suf[i] - a[i] * (n - i + 1); // Considering a[i] as max element in final array
        ll idx = upper_bound(a, a + n + 1, a[i] - x) - a - 1;
        tot += (a[i] - x) * idx - pre[idx];
        if (tot <= k) {
            return true;
        }
    }
    return false;
}

void test() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    /*
    Solution 
    We can do binary search on the ans
    (i.e minimum possible difference between max and min element). 
    let's say we want to find if it is possible to apply <=k operations 
    such that difference is less than equal to X. we can traverse the array
    and for ith element we can assume it to be the min. element 
    than max. value must be a[i]+X; so now all the values less than a[i] 
    must be made equal to a[i] and all values greater than a[i]+x must be 
    made equal to a[i]+X, so we can find number of operations required to 
    achieve this if we sort the original array and keep prefix sum, 
    similarly we will assume the ith element to be max. value in array 
    and min. value will then be equal to a[i]-X. and then find number of 
    operations required. we will finally keep the min. number of operations 
    required after traversing the array so if this value is less than equal to k
    than do right = X-1; else left=X+1;
    */
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i > 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    ll lo = 0, hi = 1e18, mid, ans = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    fast_io();
    #ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout << fixed << setprecision(15);
    test();
    #ifdef HOME
        cout << "Time: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << "ms";
    #endif
    return 0;
}