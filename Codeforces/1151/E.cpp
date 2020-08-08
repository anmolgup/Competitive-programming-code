#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }
    long long int g=0;
    for (long long int i=0;i<=n-2;i++)
    {
        if (arr[i]<arr[i+1])
        {
            g=g+((arr[i+1]-arr[i])*(n-arr[i+1]+1));
        }
        else
        {
            g=g+(arr[i+1]*(arr[i]-arr[i+1]));
        }
    }
    g=g+(arr[0]*(n-arr[0]+1));
    cout << g << endl;
    return 0;
}