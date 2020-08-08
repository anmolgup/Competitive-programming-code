#include<bits/stdc++.h>
using namespace std;
 
int findTrailingZeros(int n) {
int count=0;
while(n){
n /= 5;
count += n;
}
return count;
}
 
int main()
{
    int m;
    cin>>m;
    vector<int> v;
    int i,cnt=0;
    for(i=1;;i++)
    {
        if(findTrailingZeros(i)==m)
        {
            cnt++;
            v.push_back(i);
        }
        if(findTrailingZeros(i)>m)
        {
            break;
        }
    }
    cout<<cnt<<endl;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}