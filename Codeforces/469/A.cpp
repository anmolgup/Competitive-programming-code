#include <iostream>
#include<unordered_map>
using namespace std;
int main() {
    int n; cin>>n;
    unordered_map<int,bool> mymap;
 
    int p; cin>>p;
 
    for(int i=0;i<p;i++){
        int num; cin>>num;
        mymap[num]=true;
    }
 
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int num; cin>>num;
        mymap[num]=true;
    }
    
    cout<<(mymap.size()==n?"I become the guy.":"Oh, my keyboard!");
    return 0;
 
}