
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
 
#define watch(x) cout << (#x) << " is " << (x) << endl
 
 
using namespace std;
int main() {
 
ios::sync_with_stdio(false); // makes cin and cout as fast and scanf printf
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int c;
    int test_n = 1;
    cin>>c;
    while(c--){
        int n,k,b,t;
        //scanf("%d%d%d%d",&n,&k,&b,&t);
        cin>>n>>k>>b>>t;
 
 
        int X[n];
        int V[n];
        for (int i = 0; i < n ; ++i) {
            cin >> X[i]; // increasing order
 
        }
        for (int i = 0; i < n ; ++i) {
            cin >> V[i];
 
        }
        if (k == 0){
            //printf("Case #%d: 0\n",test_n++);
            cout<<"Case #"<<test_n++<<": "<<0<<"\n";
            continue;
        }
        int ans=0;
        int fail_chicken = 0;
        for (int i = n-1;i>=0;i--){
            double finish_time = ((double)( b-X[i] ) /V[i]);
            //watch(finish_time);
            if (finish_time <= t){
                k--;
                ans+=fail_chicken;
            }else{
                fail_chicken++;
            }
            if (k == 0){
                cout<<"Case #"<<test_n++<<": "<<ans<<"\n";
                //printf("Case #%d: %d\n",test_n++,ans);
                break;
            }
            else if (i -k < 0) {
                //printf("Case #%d: IMPOSSIBLE\n", test_n++);
                cout<<"Case #"<<test_n++<<": IMPOSSIBLE\n";
                break;
            }
 
 
        }
 
    }
 
    return 0;
