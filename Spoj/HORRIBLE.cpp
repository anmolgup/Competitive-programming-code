#include<bits/stdc++.h>
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
#define w(x)  int x; cin>>x; while(x--)
#define uni(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define ini(a, v)       memset(a, v, sizeof(a))
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr ll inf = 1999999999999999997;
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 4000400;
// Debugging
ll tree[400400];
ll lazy[400400];
ll query(ll idx, ll queryStart, ll queryEnd, ll treeStart, ll treeEnd) {
	if (lazy[idx] != 0) {
		tree[idx] += (treeEnd - treeStart + 1) * lazy[idx];
		if (treeStart != treeEnd) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (treeStart > treeEnd or queryStart > treeEnd or queryEnd < treeStart) {
		return 0;
	}
	if (treeStart >= queryStart and treeEnd <= queryEnd) {
		return tree[idx];
	}
	ll mid = (treeEnd + treeStart)/2;
	return query(2 * idx, queryStart, queryEnd, treeStart, mid) + query(2 * idx + 1, queryStart, queryEnd, mid + 1, treeEnd);
}
void update(ll idx,ll updateStart,ll updateEnd,ll treeStart,ll treeEnd,ll val){
	if(lazy[idx] != 0){
		tree[idx] += (treeEnd - treeStart + 1)*lazy[idx];
		if(treeStart != treeEnd){
			lazy[2*idx] += lazy[idx];
			lazy[2*idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(treeStart > treeEnd or treeStart > updateEnd or treeEnd < updateStart){
		return ;
	}
	if(treeStart >= updateStart and treeEnd <= updateEnd){
		tree[idx] += (treeEnd - treeStart + 1)*val;
		if(treeStart != treeEnd){
			lazy[2*idx] += val;
			lazy[2*idx + 1] += val;
		}
		return ;
	}
	ll mid = (treeStart + treeEnd) >> 1;
    update(2*idx,updateStart,updateEnd,treeStart,mid,val);
    update(2*idx+1,updateStart,updateEnd,mid+1,treeEnd,val);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	w(t) {
		ll n, c;
		cin >> n >> c;
		ms(tree,0);
		ms(lazy,0);
		ll temp,a,b;
		while(c--){
			cin >> temp >> a >> b;
			if(temp){
				cout<<query(1,a,b,1,n)<<endl;
			}
			else{
				cin >> temp;
				update(1,a,b,1,n,temp);
			}
		}

	}
}
