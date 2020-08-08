#include<bits/stdc++.h>
using namespace std;
const int MX = 170 , inf = (1<<29);
int dp[MX][MX];
/* dp array is the array we are storing our algorithm results in
   dp will be initalized with weights of our edges
*/
int T , n , List[MX] , Tn;
vector < int > Queries[MX];
int lquery[10000] , rquery[10000] , ans[10000];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        //clearing everything
        for(int j = 1 ; j <= n ; j++){
            for(int i = 1 ; i <= n ; i++)
                dp[j][i] = inf;
            Queries[j].clear();
        }
        for(int j = 1 ; j <= n ; j++){
            dp[j][j] = 0;
            // this is mandatory
            for(int i = j + 1 ; i <= n ; i++){
                int x;
                cin>>x;
                if(x != -1)
                    dp[j][i] = dp[i][j] = x;
            }
        }
        int K;
        cin>>K;
        for(int j = 1 ; j <= K ; j++) cin>>List[j];
        int QN;
        cin>>QN;
        for(int j = 1 ; j <= QN ; j++){
            int coef;
            cin>>coef>>lquery[j]>>rquery[j];
            if(coef == 0) ans[j] = dp[lquery[j]][rquery[j]];
            else Queries[coef].push_back(j);
            // coef = 0 then our shortest consists of only 1 edge
            // and passes by no intermediate nodes
        }
        for(int C = 1 ; C <= K ; C++){
            int node = List[C];
            // taking next node in the exciting list
            for(int j = 1 ; j <= n ; j++)
                for(int i = 1 ; i <= n ; i++)
                    dp[j][i] = min(dp[j][i] , dp[j][node] + dp[node][i]);
            // extending chains by adding this node
            for(auto Q : Queries[C])
                ans[Q] = dp[lquery[Q]][rquery[Q]];
            // answering all queries with K = C
        }
        printf("Case %d: ",++Tn);
 
        for(int j = 1 ; j <= QN ; j++){
            if(j > 1) cout<<' ';
            if(ans[j] == inf) ans[j] = -1;
            cout<<ans[j];
        }
        puts("");
    }
