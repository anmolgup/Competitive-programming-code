#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
//#define endl "\n"
const ll mod = 1000000007;
vector <set<int>> g(1005);

void testCase() {
    int n;
    cin >> n;
    set <int> ver;
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert (v);
        g[v].insert (u);
    }
    for (int i=1; i<=n; i++)
        ver.insert (i);
    while(1) {
        //find leaf nodes and delete
        int u, v;
        u = v = -1;
        int on = -1;
        for (int i=1; i<=n; i++) {
            if (g[i].size() == 1) {
                if (u == -1) {
                    u = i;
                }
                else if (v == -1) {
                    v = i;
                    break;
                }
            }
        }
        if (v == -1) {
            cout << "! " << *ver.begin() << endl;
            return;
        }
        cout << "? " << u << " " << v << endl;
        int w;
        cin >> w;
        if (w == u || w == v) {
            cout << "! " << w << endl;
            return;
        }
        //delete u and v
        int pu = *g[u].begin();
        int pv = *g[v].begin();
        g[pu].erase (u);
        g[pv].erase (v);
        g[u].clear();
        g[v].clear();
        ver.erase (u);
        ver.erase (v);
    }
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}