#include "bits/stdc++.h"
#define sz(x) int(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	map<string,set<string>>m;
	rep(i,0,n){
		string s;
		cin>>s;
		int k;
		cin>>k;
		rep(j,0,k){
			string temp;
			cin>>temp;
			m[s].insert(temp);
		}
	}
	cout<<sz(m)<<endl;
	for(auto i:m){
		cout<<i.first<<" ";
		vector<string>temp(i.second.begin(),i.second.end());
		sort(temp.begin(),temp.end(),[](string a,string b){
			return sz(a)>sz(b);
		});
		vector<string>ans;
		rep(j,0,sz(temp)){
			bool good=1;
			rep(k,0,j){
				if(temp[k].substr(sz(temp[k])-sz(temp[j]),sz(temp[j]))==temp[j])good=0;
			}
			if(good){
				ans.push_back(temp[j]);
			}
		}
		cout<<sz(ans)<<" ";
		for(auto j:ans)cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}