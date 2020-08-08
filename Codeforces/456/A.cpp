#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n; cin>>n;
    vector<pair<int,int> > v;
    while(n--){
        int a,b; cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
 
    sort(v.begin(),v.end());
 
    // for(auto i: v){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
 
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1].second<v[i].second) {
        cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
    return 0;
}