#include <stdio.h> 

int main(void) { 
// your code here 

int *arr = (int*)malloc(100*sizeof(int)); 
for(int i=0;i<=100;i++) 
scanf("%d",arr+i); 

for(int i=0;i<=100-1;i++){ 
if(*(arr+i)==42)break; 
printf("%d\n",*(arr+i)); 
} 
return 0; 
