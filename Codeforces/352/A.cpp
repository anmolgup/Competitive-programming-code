#include <bits/stdc++.h>
using namespace std;

void printLargestDivisible(int n,int a[])
{
    int i,c0=0,c5=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
            c0++;
        else
            c5++;
    }
    c5=floor(c5/9)*9;
    if(c0==0)
        cout<<-1;
    else if(c5==0)
        cout<<0;
    else
    {
        for(i=0;i<c5;i++)
            cout<<5;
        for(i=0;i<c0;i++)
            cout<<0;
    }

}
// Driver Program to test above function
int main()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    printLargestDivisible(n,a);
}