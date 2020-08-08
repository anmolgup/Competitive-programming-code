#include<bits/stdc++.h>

long long int check(long long int a)//Function to check whether a number is prime or not
{
    long long int i,k;
    k=sqrt(a);
    for(i=2;i<=k;++i)
    {
        if(a%i==0) // if not prime
            return check(a/i); //then find greatest prime
    }
    return a;
}

int main()
{
    int j=1,t;
    long long int n,a,prod,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==0)
            prod=-1;
        else 
            prod=1;
        while(n--)
        {
            scanf("%lld",&a);
            prod*=a;
        }
        ++prod;
        printf("Case #%d: %lld\n",j,check(prod));
        j++;
    }
    return 0;
