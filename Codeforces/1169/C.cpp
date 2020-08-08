#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
const ll N = 3e5+5;
ll n, m;
vector<ll>a(N);
bool ok(ll maxi) {
    ll prev = 0;
    FOR(i,0,n-1) {
        if(prev <= a[i]) {
            ll k= m - (a[i] - prev);
            if(k > maxi) prev = a[i];
        } else {
            ll k= prev - a[i];
            if(k > maxi) 
                return false;
        }
    }
    return true;
}
int main()
{
   cin>>n>>m;
    FOR(i,1,n) cin>>a[i-1];
    
    ll l,r;
    l = 0, r = m;
    while((r-l)>1) {
        ll mid = l + (r-l)/2;
        if(ok(mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    
    if(ok(l)) 
        return !printf("%lld",l);
    printf("%lld",r);
    return 0;
}