#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
//Optimisations
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
//shortcuts for functions
#define pb emplace_back
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
// utility functions shortcuts
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define sswap(a,b) {a=a^b;b=a^b;a=a^b;}
#define swap(a,b) {auto temp=a; a=b; b=temp;}
#define set0(dp) memset(dp,0,sizeof(dp));
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
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
#define w(x)  ll x; cin>>x; while(x--) 
#define uni(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define ini(a, v)       memset(a, v, sizeof(a))
template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T>>;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Constants
constexpr ll dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
constexpr ll dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr ll inf = 1999999999999999997; 
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<ll>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 100006;
// Debugging 
#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> ll SIZE(const T (&t)[N]){ return N; } template<typename T> ll SIZE(const T &t){ return t.size(); } string to_string(string s, ll x1=0, ll x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(bool b) { return (b ? "true" : "false"); } string to_string(char c){ return string({c}); } template<size_t N> string to_string(bitset<N> &b, ll x1=0, ll x2=1e9){ string t = ""; for(ll __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(A (&v), ll x1=0, ll x2=1e9, C... coords); ll l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(A (&v), ll x1, ll x2, C... coords) { ll rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgs(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgs(__VA_ARGS__); cout << endl;
ll V,E;
set<ll >bad[maxn];
vpll edge[maxn];
ll dist[maxn];
priority_queue<pll> q;
ll used[maxn];
ll next(ll x,ll t){
	while(bad[x].find(t) != bad[x].end()) t++;
	return t;
}
void add(ll x,ll d){
	if(d < dist[x]){
		dist[x] = d;
		q.push(mp(-d,x));
	// dbgm(x,d);
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll x,y,d,t;
	cin >> V >> E;
	forr(i,E){
		cin >> x >> y >> d;
		x--;
		y--;
		edge[x].pb(mp(y,d));
		edge[y].pb(mp(x,d));
	}
	forr(i,V){
		ll cnt;
		cin >> cnt;
		forr(j,cnt){
			cin >> t;
			bad[i].insert(t);
		}
	}
	forr(i,V) dist[i] = INT_MAX;
	add(0,0);
	// dbg(bad);
	while(!q.empty()){
		x = q.top().ss;
		t = -q.top().ff;
		q.pop();
		if(used[x]) continue;
		used[x] = true;
		t = next(x,t);
		forr(i,edge[x].size()){
			ll y = edge[x][i].ff;
			ll t2 = t + edge[x][i].ss;
			add(y,t2);
		}
	}
	if(dist[V - 1] == INT_MAX) cout<<"-1";
	else cout<<dist[V - 1];

}