#include <bits/stdc++.h>
#include <stdio.h>

#define lli long long int
lli mod =1000000007;
lli dp[2001][2001]={{0}};


int main(int argc, char const *argv[]) {
  int n=0,k=0;
  int i=0,j=0;
  int t=1;
lli ans=0;
  scanf("%d %d",&n,&k);

  for (t = 1; t<=n; t++) {
    dp[t][1] = 1;
  }

  // for (i = 2; i <= k; i++) {
  //   for (j=2; j <=n; j++) {
  //     for (t = 1; t <= n; t++) {
  //       dp[j][i] += dp[j/t][i-1]%mod;
  //       dp[j][i] %= mod;
  //     }
  //   }
  // }

for(int t=2;t<=k;t++){
  for (i = 1; i <= n; i++) {
   for (int j = i; j <= n; j += i){
      dp[j][t]=(dp[i][t-1]+dp[j][t])% mod;
   }
 }
}
for(int i=1;i<=n;i++){
  ans=(ans+dp[i][k])% mod;
}
  printf("%lld\n",ans);
  return 0;
}