// kya hi fark padta hai...

#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define o_set(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
// greater<T> for set to be in decreasing order
// 1. order_of_key(k) : number of elements strictly lesser/greater than k
// 2. find_by_order(k) : k-th element in the set (0 indexing)

#define rep(i,st,en) for(__typeof(en) i=(st)-(st>en); i!=(en)-(st>en); i+=1-2*(st>en))
#define ff first
#define ss second
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define go_karuna ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << *it << " = " << a << endl; err(++it, args...);}
typedef long long ll;
const ll mod = 1e9+7;

vector<int> par(20001), sz(20001, 1);

int find(int v) {
  if(v == par[v])
    return v;
  return par[v] = find(par[v]);
}

void _union(int a, int b) {
  a = find(a);
  b = find(b);
  if(a != b) {
    if(sz[a] > sz[b])
      swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
  }
}

int main() {
    go_karuna
    int n;  cin>>n;
    int k;  cin>>k;
    iota(all(par), 0);
    rep(i,0,k) {
      int x, y; cin>>x>>y;
      _union(x, y);
    }
    int m;  cin>>m;
    rep(i,0,m) {
      int x, y; cin>>x>>y;
      if(find(x) == find(y)) {
        sz[find(x)] = 0;
      }
    }
    int ans = 0;
    rep(i,1,n+1)  ans = max(ans, sz[find(i)]);
    cout<<ans<<endl;
    return 0;
}