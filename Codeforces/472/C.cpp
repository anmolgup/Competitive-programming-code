#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <map>

using namespace std;


int main() {
    int n; cin>>n;
    vector<pair<string,string> > v(n + 1);
    for(int i = 1;i <= n;i++) {
        cin>>v[i].first>>v[i].second;
    }
    vector<int> perm(n);
    for(int i = 0;i < n;i++) {
        cin>>perm[i];
    }
    string ps = min(v[ perm[0] ].first,v[ perm[0] ].second);
    for(int i = 1;i < n;i++) {
        if(v[perm[i]].first <= ps && v[perm[i]].second <= ps) {
            cout<<"NO"<<endl;
            return 0;
        }
        else {
            string tmp = ps;
            if(v[perm[i]].first > ps) ps = v[perm[i]].first;
            if(v[perm[i]].second > tmp && ps == v[perm[i]].first) ps = min(v[perm[i]].first,v[perm[i]].second);
            else if(v[perm[i]].second > tmp) ps = v[perm[i]].second;
        }
    }
    cout<<"YES"<<endl;

    
    
}