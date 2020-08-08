#include<stdio.h>
int main()
{   int i, count=1;
    char num[100];
    scanf("%s",&num);
    for(i=1; num[i]!='\0'; i++)
    {   if(num[i]==num[i-1]){count++;}
        else {count = 1;}
        if(count>=7)
        {printf("YES\n");break;}
    }
    if(num[i]=='\0'){printf("NO");}
return 0;
}