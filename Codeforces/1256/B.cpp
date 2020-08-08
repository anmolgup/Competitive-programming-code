#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define N 100005
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
ll po(ll a, ll x,ll m){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; }
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("a.txt", "w", stdout);
    #endif
     int Q;
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i=0; i<N; i++) cin >> A[i];
        int s = 0;
        while(s < N-1){
            int mn = min_element(A.begin()+s, A.end()) - A.begin();
            for(int i=mn; i>s; i--) swap(A[i-1], A[i]);
            s = max(mn, s+1);
        }
        for(int i=0; i<N; i++) cout << A[i] << " \n"[i==N-1];
    }
return 0;
}