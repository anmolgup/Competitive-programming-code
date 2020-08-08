#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vi vector<int>
#define vll vector<ll>
#define forr(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define int ll
ll po(ll a, ll x, ll m) { if (x == 0) {return 1;} ll ans = 1; ll k = 1;  while (k <= x) {if (x & k) {ans = ((ans * a) % m);} k <<= 1; a *= a; a %= m; } return ans; }
int n, m;
string s[11];
int vis[11][26];
string rec(int pos, string temp) {
    if (pos == m) {

        int mx  = 0;
        forr(i, n) {
            int tmp = 0 ;
            forr(j, m) {
                if (s[i][j] != temp[j])
                    tmp++;
            }
            mx = max(tmp, mx);
        }
        string ans = "";

        if (mx > 1) {
            return ans;
        } else {

            return temp;
        }
    }
    string ans ;
    forr(i, n) {
        string k =  temp + s[i][pos];
        int mx  = 0;
        forr(i, n) {
            int tmp = 0 ;
            forr(j, k.length()) {
                if (s[i][j] != k[j])
                    tmp++;
            }
            mx   = max(mx, tmp);
        }
        if (mx > 1) {
            continue;

        }
        if (vis[pos][s[i][pos] = 'a']) {
            continue;
        }
        vis[pos][s[i][pos] - 'a'] = 1;
        ans  = rec(pos + 1, k);
        if (ans.length() == m)
            break;
    }
    return ans ;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("a.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        ms(vis, 0);
        cin >> n >> m;
        forr(i, n) {
            cin >> s[i];
        }
        string temp = "";
        string ans = rec(0, temp);
        if (ans.length() == m) {
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}