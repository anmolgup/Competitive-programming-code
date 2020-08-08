#include <bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(__typeof(en) i=(st)-(st>en); i!=(en)-(st>en); i+=1-2*(st>en))
#define ff first
#define ss second
#define endl '\n'
#define all(v) v.begin(), v.end()
#define cases() int no_of_tc; cin>>no_of_tc; for(int testcase=1;testcase<=no_of_tc;++testcase)
#define deb(args...) err(args);
void err() {cout<<endl;}
template<typename T, typename... More> void err(T arg, More... more){cout<<arg<<' '; err(more...);}
typedef long long ll;
const ll mod = 1e9+7;

int main() {
    cases() {
        ll n;   cin>>n;
        ll ans = 0;
        while(n) {
            ans += n;
            n >>= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}