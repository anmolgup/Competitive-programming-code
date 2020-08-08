#include<bits/stdc++.h>
using namespace std;
//Optimisations
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
//shortcuts for functions
#define pb push_back
#define mp make_pair
#define ff first 
#define ss second
#define endl "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define th(n) cout<<n<<endl
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
// make it python 
#define gcd __gcd
#define append push_back
#define str to_string
#define stringtoll stoll
#define upper(s) transform(s.begin(),s.end(),s.begin(),::toupper)
#define lower(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define print(arr) for(auto el: arr) cout<<el<<" ";cout<<endl
// utility functions shortcuts
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define sswap(a,b) {a=a^b;b=a^b;a=a^b;}
#define swap(a,b) {auto temp=a; a=b; b=temp;}
#define set0(dp) memset(dp,0,sizeof(dp));
#define bits(x) __builtin_popcount(x)
#define SORT(v) sort(all(v))
#define forr(i,n) for(ll i=0;i<n;i++)
#define formatrix(i,n) for(ll i=0;i<n;i++, cout<<"\n")
#define eof (scanf("%d" ,&n))!=EOF
// declaration shortcuts
#define vll vector<ll>
#define vvl vector<vector<ll>> 
#define vpll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define ppl pair<ll,pll>
#define ull unsigned long long
#define ll long long
#define mll map< ll, ll > 
#define sll set< ll > 
#define uni(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define ini(a, v)       memset(a, v, sizeof(a))
template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T>>;
// Constants
constexpr int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr ll inf = 1999999999999999997; 
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 200006;
// Debugging 
#define n_l '\n'
void test() {
	ll n,k;
	cin >> n >> k;
	string ans = "YES";
	if(n%2 != k%2)
		ans = "NO";
	ll maxsum  = k*k;
	if(n < maxsum)
		ans = "NO";
	th(ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        test();
    }
    return 0;
}