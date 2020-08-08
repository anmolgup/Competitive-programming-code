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
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,d;
    cin>>n>>m>>d;
    d--;
    vi v(m);
    forr(i,m){
        cin>>v[i];
    }   
    int leftover = n-accumulate(all(v),0);
    if(leftover>(m+1)*d){
        cout<<"NO"<<"\n";
        return 0;
    }
    cout<<"YES"<<"\n";
    forr(i,m+1){
        int t = min(leftover,d);

        leftover-=t;
        forr(j,t)
            cout<<"0 ";
        if(i<m){
        forr(j,v[i])
            cout<<i+1<<" ";
        }
    }
    cout<<"\n";
return 0;
}