#include<stdio.h>
int main() {
  int a;
  scanf("%d\n",&a);
 // int b = a%2;
  //printf("remainder is %d\n",b);
  if(!(a%2)&&a!=2)
    printf("YES\n");
  else
      printf("NO\n");
  return 0;
}