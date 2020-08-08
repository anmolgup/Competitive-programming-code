#include<stdio.h>
#include<math.h>
int max(int a,int b) {
 return a>b?a:b;
}
int main() {
 int t,n,i,b[202],j,temp;
 char a[200];
 for(scanf("%d",&t);t;t--) {
  scanf("%d%s",&n,a);
  b[0]=0;
  b[1]=a[0]-48;
  for(i=2;i<=n;i++) {
   temp=0;
   b[i]=b[i-1];
   for(j=i;j>0;j--) {
    if(a[j-1]=='1')
     temp++;
    else
     temp--;
    if(temp>0) {
     b[i]=max(b[i],i-j+1+b[j-1]);
    }
   }
  }
  printf("%d\n",b[n]);
 }
 return 0;
