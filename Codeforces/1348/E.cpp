#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
//increase stack size
#pragma comment(linker, "/STACK:16777216")

ll mxm() {return LLONG_MIN;}
template<typename... Args>
ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }

ll mnm() {return LLONG_MAX;}
template<typename... Args>
ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }

template<class T> ostream& operator<<(ostream& os,vector<T> V){
	os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream& os,pair<L,R> P){
	return os<<"("<<P.first<<","<<P.second<<")";
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
	const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

#define ld long double
#define pll pair<ll,ll>
#define ii pair<int,int>
#define vll vector<ll>
#define vii vector<ii>
#define vi vector<int>
#define vpll vector<pll>
#define vld vector<ld>
#define vvld vector<vld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpll vector<vpll>
#define vvii vector<vii>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x)	x.begin(),x.end()

const int mod=1e9+7;
// 128 bit: __int128
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}

struct compare{
	bool operator() (const int &a,const int &b) const{
		return a>b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll n, k;
	cin >> n >> k;
	vpll v(n);
	ll a = 0, b = 0, ans = 0, ans1 = 0, rema = 0, remb = 0;;
	for(ll i = 0; i < n; i++){
		cin >> v[i].F >> v[i].S, a += v[i].F, b += v[i].S, ans1 += (v[i].F + v[i].S) / k;
		ll diff = (v[i].F + v[i].S) % k;
		if(diff <= v[i].F)
			rema += diff;
		if(diff <= v[i].S)
			remb += diff;
	}
	ans = a / k + b / k;
	a %= k, b %= k;
	for(ll i = 0; i < n; i++){
		bool f = 0;
		for(int j = 1; j <= a; j++){
			if(v[i].F >= j && v[i].S >= k - j && k - j <= b){
				ans++;
				f = 1;
				break;
			}
		}
		if(f) break;
	}
	if(rema >= k || remb >= k)
		ans1++;
	ans = max(ans, ans1);
	cout << ans << endl;
}