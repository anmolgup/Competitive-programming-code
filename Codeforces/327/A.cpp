#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int curans = 0;
            for(int k=0;k<n;k++)
                if(k>=i&&k<=j)
                    curans+=1-v[k];
                else
                    curans+=v[k];
            ans = max(ans,curans);
        }
    }
    cout<<ans<<endl;
 
    return 0;
}