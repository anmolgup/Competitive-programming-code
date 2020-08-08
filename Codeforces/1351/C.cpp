#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        // we need a map storing two pairs, 
        // one for the point Skier is going from, let's say p1
        // another for the point Skier is going to, let's say p2
        map<pair<pair<int,int>,pair<int,int>>,bool> m;
        int x=0,y=0,ans=0;
        
        for(char c : s){
            pair<int,int> p1,p2;
            p1=make_pair(x,y);
            // for four directions, store the coordinate (x,y) to a pair
            if(c=='S') {
                p2 = make_pair(x,--y);
            }else if(c=='N'){
                p2 = make_pair(x,++y);
            }else if(c=='W'){
                p2 = make_pair(--x,y);
            }else if(c=='E'){
                p2 = make_pair(++x,y);
            }
            // if this point is visited, add 1
            if(m[{p1,p2}]) ans++;
            else {
                // if not, add 5
                ans+=5;
                // set both from & to pair to true
                m[{p1,p2}]=m[{p2,p1}]=true;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}