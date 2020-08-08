#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
 
#define REP(a,b) for (int (a)=0; (a) < (b); (a)++)
#define FOR(a,b,c) for (int (a)=(b); (a) <= (c); (a)++)
#define RESET(a,b) memset((a),b, sizeof (a))
 
#define PII pair<int,int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define INF 2123123123
#define MAXN 1000005
 
using namespace std;
 
char sc[MAXN];
int faf[MAXN];
int N, T;
 
void build(){
   int i,j;
    
   i = 0;
   j = -1;
   faf[0] = -1;
   while (i < N){
      while ((j >= 0) && (sc[i] != sc[j])) j = faf[j];
             
      i++;
      j++;
      faf[i] = j;
   }
}
 
int main(){   
   scanf("%d", &T);
   REP(jt,T){
      scanf("%d", &N);
      scanf("%s", sc);
       
      sc[N++] = '.';
      build();
       
      printf("Test case #%d\n", 1+jt);
      REP(i,N){
         if ((i%(i-faf[i]) == 0) && (faf[i] >= i-faf[i])){
            printf("%d %d\n", i, i/(i-faf[i]));
         }
      }
      printf("\n");
   }
 
   return 0;   
