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

void test();

vector<pii> a[2];
int req[10000];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	f(i,0,m){
		int t,l,r;
		cin >> t >> l >> r;
		a[t].pb({l,r});
	}
	sort(all(a[1]));
	int value = 1e8;
	if(a[1].empty()){
		cout << "Yes\n";
		f(i,0,n){
			cout << n-i << " ";
		}cout << "\n";
		return 0;
	}
	f(i,a[1][0].F,a[1][0].S+1){
		req[i] = value;
	}
	int end = a[1][0].S;
	f(i,1,a[1].size()){
		if(a[1][i].F<=end){
			f(j,end+1,a[1][i].S+1){
				req[j] = value;
			}
			end = max(end,a[1][i].S);
		}else{
			value -= 1001;
			f(j,a[1][i].F,a[1][i].S+1){
				req[j] = value;
			}
			end = a[1][i].S;
		}
	}
	if(req[1] == 0){
		value = 1e9;
	}
	f(i,1,n+1){
		if(req[i] == 0){
			req[i] = value;
			value--;
		}else{
			value = req[i]-1;
		}
	}
	bool flag = false;
	f(i,0,a[0].size()){
		if(req[a[0][i].F] == req[a[0][i].S]){
			flag = true;
		}
	}
	if(flag){
		cout << "No\n";
	}else{
		cout << "Yes\n";
		f(i,1,n+1){
			cout << req[i] << " ";
		}cout << "\n";
	}
	return 0;
}