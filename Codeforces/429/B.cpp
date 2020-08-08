#include <iostream>
#include <algorithm>
#include <string.h>
 
#define MOD 1000000007
 
using namespace std;
 
const int NN = 1005;
 
int boy_start[NN][NN];
int boy_end[NN][NN];
int girl_start[NN][NN];
int girl_end[NN][NN];
int calorie[NN][NN];
 
int maxCalories(int M, int N){
   
    //building boy_start[][] table in bottom up fashion
    //Here boy_start[i][j] --> the max calories that can be burnt if the boy
    //starts from (1,1) and goes up to (i,j)
    for(int i = 1;i<=M;i++){
        for(int j = 1;j<=N;j++){
            boy_start[i][j] = calorie[i][j] + max(boy_start[i-1][j], boy_start[i][j-1]);
        }
    }
   
    //building girl_start[][] table in bottom up fashion
    //Here girl_start[i][j] --> the max calories that can be burnt if the girl
    //starts from (M,1) and goes up to (i,j)
    for(int i = M;i>=1;i--){
        for(int j = 1;j<=N;j++){
            girl_start[i][j] = calorie[i][j] + max(girl_start[i+1][j], girl_start[i][j-1]);
        }
    }
   
    //building boy_end[][] table in bottomup fashion which specifies the journey from end to start
    //Here boy_end[i][j] --> the max calories that can be burnt if the boy start
    //from end i.e. (M,N) and comes back to (i,j)
    for(int i = M;i>=1;i--){
        for(int j = N;j>=1;j--){
            boy_end[i][j] = calorie[i][j] + max(boy_end[i+1][j], boy_end[i][j+1]);
        }
    }
   
    //building girl_end[][] table in bottomup fashion which specifies the journey from end to start
    //Here girl_end[i][j] --> the max calories that can be burnt if the girl start
    //from end i.e. (1,N) and comes back to (i,j)
    for(int i = 1;i<=M;i++){
        for(int j = N;j>=1;j--){
            girl_end[i][j] = calorie[i][j] + max(girl_end[i-1][j], girl_end[i][j+1]);
        }
    }
   
    //Iterate over all the possible meeting points i.e. between (2,2) to (M-1,N-1)
    //consider this point as the actual meeting point and calculate the max possible answer
    int ans = 0;
    for(int i = 2;i<M;i++){
        for(int j = 2;j<N;j++){
           
            int ans1 = boy_start[i][j-1] + boy_end[i][j+1] + girl_start[i+1][j] + girl_end[i-1][j];
           
            int ans2 = boy_start[i-1][j] + boy_end[i+1][j] + girl_start[i][j-1] + girl_end[i][j+1];
           
            ans = max(ans, max(ans1, ans2));
        }
    }
    return ans;
}
 
int main()
{
    memset(boy_start,0,sizeof boy_start);
    memset(boy_end,0,sizeof boy_end);
    memset(girl_start,0,sizeof girl_start);
    memset(girl_end,0,sizeof girl_end);
    memset(calorie,0,sizeof calorie);
    int M,N;
    cin>>M>>N;
    for(int i = 1;i<=M;i++){
        for(int j = 1;j<=N;j++)
            cin>>calorie[i][j];
    }
    cout<<maxCalories(M,N)<<endl;
    return 0;
}