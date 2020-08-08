#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define print(x) cerr << (#x) << "is "<< x << "\n"
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	int ans = INT_MAX,val;
	f(i,1,1000+1){
		int op = 0;
		int num = i;
		f(j,0,n){
			if(a[j]-num!=0){
				op++;
			}
			num+=k;
		}
		if(op<ans){
			ans = op;
			val = i;
		}
	}
	int num = val;
	cout << ans << "\n";
	f(i,0,n){
		if(a[i]-num>0){
			cout << "- " << i+1 << " " << a[i]-num << "\n";
		}else if(a[i]-num<0){
			cout << "+ " << i+1 << " " << -a[i]+num << "\n";
		}
		num+=k;
	}
	return 0;
}