#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
//#define debug(x) cout <<#x<<" "<<endl;
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define MOD9 1000000009
#define ll long long
#define gc getchar_unlocked
#define eps 1e-8
#define ms(s,n) memset(s,n,sizeof(s))
#define bolt ios::sync_with_stdio(false)
const double pie = 2 * acos(0.0);
#define prec(n) fixed<<setprecision(n)
#define eof (scanf("%d",&n))!=EOF
#define Unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EraseSpace(s) s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
#define leftrotate(str, n) rotate(str.begin(), str.begin()+n, str.end());
#define rightrotate(str, n) rotate(str.begin(), str.begin()+str.size()-n, str.end());
int ar[100];
int solve(int l, int r) {
	int mid = (l + r) / 2;
	int ans = 1; int ok = true;
	for(int i = l + 1; i <= r; i++) {
		if(ar[i - 1] <= ar[i]) ans++;
		else ok = false;
	}
	if(ok) return ans;
	return max(solve(l, mid), solve(mid + 1, r));
}

int main()
{  
    bolt; // *TeZ*
    cin.tie(NULL);
    cout.tie(NULL); 
    int n; 
    cin >> n; int ans = INT_MIN; int sz = 0;
	for(int i = 0; i < n; i++) cin >> ar[i];
		cout << solve(0, n - 1) << endl;

}