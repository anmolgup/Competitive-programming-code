#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define INF 9223372036854775807
const ll mod=1e9+7;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=1;
    for(ll i=2;i<=200000;i++){
        while(1){
            ll f=2;
            for(ll j=0;j<n;j++){
                if(a[j]%i!=0) f--;
                if(f<=0) break;
            }
            if(f<=0) break;
            for(ll j=0;j<n;j++)
                if(a[j]%i==0)
                    a[j]/=i;
            ans*=i;
        }
    }
    cout<<ans;

    return 0;
}