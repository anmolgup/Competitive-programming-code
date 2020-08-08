#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define mod 1000000007
#define fi first
#define se second
#define pii pair<int,int>
//#define push_back emplace_back
//#define push emplace
//#define insert emplace
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
#define LONGLONG_MAX 10000000000000000
using namespace std;
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
auto power(auto a,long long b){
    auto ans=1;
    //cout<<ans;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    ///cout<<ans<<" ";    
    return ans;
        
}
void maxi(auto &a,auto b){
	a=max(a,b);
}
void mini(auto &a,auto b){
	a=min(a,b);
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	set<int>s;
	map<int,int>m;
	for(int i=0;i<k;i++){
		m[a[i]]++;
		if(m[a[i]]==1)s.insert(a[i]);
		else s.erase(a[i]);

	}
	for(int i=0;i<=n-k;i++){
		if(s.empty()){
			cout<<"Nothing"<<endl;
		}
		else{
			auto it=s.end();
			it--;
			cout<<*it<<endl;
		}
		m[a[i+k]]++;
		m[a[i]]--;
		if(m[a[i]]==1)s.insert(a[i]);
		else s.erase(a[i]);
		if(m[a[i+k]]==1)s.insert(a[i+k]);
		else s.erase(a[i+k]);
	}
	return 0;
}