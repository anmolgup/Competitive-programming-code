#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char arr[12][12];
    memset(arr,'0',sizeof(arr));

    int n,m,count=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]=='P'&&arr[i][j+1]=='W')
            {
                count++;
                arr[i][j+1]='.';
            }
            else  if(arr[i][j]=='P'&&arr[i][j-1]=='W')
            {
                count++;
                arr[i][j-1]='.';
            }
            else  if(arr[i][j]=='P'&&arr[i+1][j]=='W')
            {
                count++;
                arr[i+1][j]='.';
            }
            else  if(arr[i][j]=='P'&&arr[i-1][j]=='W')
            {
                count++;
                arr[i-1][j]='.';
            }
        }
    }
        cout<<count<<endl;


    return 0;
}