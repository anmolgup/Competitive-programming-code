#include<iostream>
#include<iomanip>
#include<iterator>
#include<list>
#include<math.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<functional> 
#define sz(a) int((a).size()) 
#define pb push_back 
#define eb emplace_back
#define mp make_pair
#define debug(x)  cout<<'>'<<#x<<" : "<<x<<endl;
#define mt make_tuple
#define ld(a) while(a--)
#define tci(v,i) for(auto i=v.begin();i<v.end();i++)
#define tcf(v,i) for(auto i : v)
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define osit ostream_iterator
#define MOD 		1000000007
#define INF 		0x3f3f3f3f
#define LLINF       1000111000111000111LL
#define pi 			3.14159265358979323
#define endl '\n'
#ifdef WIN32
#define getchar_unlocked getchar
#endif
#define gc getchar
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<long long int> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
typedef set<int> si;
typedef priority_queue<ii,vii,greater<ii> > spq;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
template<typename T>void read(T &x) { register T c = gc(); x = 0; int t = 0; if (c == '-') t = 1, c = gc(); for (; (c < 48 || c>57); c = gc()); for (; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }if (t) x = -x; }
template<typename T> T pow(T x,T y){T ans=1;while(y>0){if(y%2==1) ans=(ans*x)%MOD;y/=2;x=(x*x)%MOD;}return ans;} //using this instead of inbuilt pow due to precision issues in that
int main(){
	int n,maxi=-INF;
	cin>>n; if(n==1){
		cout<<"1"; return 0;
	}
	vi v; int x; 
	rep(i,0,n){
		cin>>x; v.eb(x);
	}
	for(int i=0;i<n;i++){
		int l=1,r=0,mini=v[i];
		for(int k=i-1;k>=0;k--){
			if(v[k]>mini) break;
			++l; mini=v[k];
		}
		mini=v[i];
		for(int k=i+1;k<n;k++){
			if(v[k]>mini) break;
			++r; mini=v[k];
		}
		maxi=max(l+r,maxi);
		// debug(i);
		// debug(maxi);
	}
	cout<<maxi;
}