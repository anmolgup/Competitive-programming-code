// greedy method use a[i + 1] and a[i + 2] to calculate a[i]

#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define FER(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define N 100020
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int a[N];

int main(){

	fastio;
	int n;
	cin >> n;
	FER(i,0,n) cin >> a[i];

	if(n == 1){ cout << 3 << endl; return 0; }

	vector<int> ans;

	if(a[0] == a[1]) ans.pb(3);
	if(a[0] < a[1]) ans.pb(1);
	if(a[0] > a[1]) ans.pb(5);

	for(int i = 0; i < n-1; ++i){
		if(a[i+1] > a[i] and ans[i] == 5){
			cout << -1 << endl;
			return 0;
		}
		if(a[i+1] < a[i] and ans[i] == 1){
			cout << -1 << endl;
			return 0;
		}
		int cur;
		if(a[i+1] > a[i]){
			cur = ans[i]+1;
			if(i < n-2){
				if(a[i+2] < a[i+1]) cur = 5;
			}
		}else if(a[i+1] < a[i]){
			cur = ans[i]-1;
			if(i < n-2){
				if(a[i+2] > a[i+1]) cur = 1;
			}
		}else if(a[i+1] == a[i]){
			cur = (ans[i] == 3) ? 2 : 3;
			if(i < n-2){
				if(a[i+2] > a[i+1]) cur = (ans[i] == 1) ? 2 : 1;
				if(a[i+2] < a[i+1]) cur = (ans[i] == 5) ? 4 : 5;
			}
		}
		ans.pb(cur);
	}

	for(int x : ans) cout << x << " "; cout << endl;

	return 0;
}