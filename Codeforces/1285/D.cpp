#include <bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
  #include "header.h"
#else
  #define debug(args...)
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long lli;
typedef long double ld;

#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(auto i=(a);i<b;i++)

#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
void preprocess(void) {
  return;
}
vi a;

int solve(int l, int r, int pos) {
  if(pos == -1) return 0;
  int f1 = -1, f2 = -1;
  rep(i,l,r+1) {
    if(a[i]&(1<<pos)) {
      break;
    }
    else f1 = i;
  }
  if(a[r]&(1<<pos)) f2 = r;
  debug(f1, f2, pos);
  if(f1 == -1) {
    return solve(l, r, pos-1);
  }
  else if(f2 == -1) {
    return solve(l, r, pos-1);
  }
  else {
    int ans = 0;
    ans ^= (1<<pos);
    ans ^= min(solve(l, f1, pos-1), solve(f1+1, r, pos-1));
    return ans;
    if((a[f1]&((1<<pos)-1))<(a[f2]&((1<<pos)-1))) {
      solve(l, f1, pos-1);
    }
    else solve(f1+1, r, pos-1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int n; cin>>n;
  a.resize(n);
  rep(i,0,n) cin>>a[i];
  sort(all(a));
  /*
  map<int, int> m[30];
  rep(i,0,n) {
    int s1 = 0;
    int s2 = (1<<30)-1;
    for(int j = 29; j>=0; j--) {
      int p = (s1&a[i]);
      m[j][p] = max(a[i]&s2, m[j][p]);
      s1 += (1<<j);
      s2 ^= (1<<j);
    }
  }
  int ans = 0;
  for(int j = 29; j>=0; j--) {
    debug(m[j]);
    int p1 = m[j][ans^(1<<j)], p2 = m[j][ans];
    debug(p1, p2);
    if(p1<p2) {
      ans += (1<<j);
    }
    else continue;
  }*/
  int ans = solve(0,n-1,30);
  cout<<ans<<endl;
}