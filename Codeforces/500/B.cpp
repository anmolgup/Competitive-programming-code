#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
 
using namespace std;
 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define sz size()
 
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
 
int P[333];
int dsu[333];
string s;
int ans[333];
 
int find(int x ) {
	return (x == dsu[x]) ? x : (dsu[x] = find(dsu[x]));
}
 
vector<int > v[333],idx[333];
 
int main() {
	int n;
	S(n);
	rep(i,1,n+1) S(P[i]);
	rep(i,1,n+1) dsu[i] = i;
	rep(i,0,n) {
		cin >> s;
		rep(j,i+1,n) if(s[j] == '1') {
			int px = find(i+1);
			int py = find(j+1);
 
			if(px != py) {
				dsu[px] = py;
			}
		}
	}
 
	rep(i,1,n+1) {
		int p = find(i);
		v[p].push_back(P[i]);
		idx[p].push_back(i);
	}
 
	rep(i,1,n+1) sort(all(v[i]));
 
	rep(i,1,n+1) {
		rep(j,0,v[i].size()) {
			ans[idx[i][j]] = v[i][j];
		}
	}
 
	rep(i,1,n+1) printf("%d ",ans[i]);
	return 0;
}