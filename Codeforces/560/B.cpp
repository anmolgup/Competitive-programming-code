#include <iostream>
#define fo(i,k) for(i=0;i<k;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pb push_back
#define vi vector<int>
using namespace std;
const int mod = 1000000007;
int a2,a3,b2,b3;
bool f(int x,int y)
{
    if(a2+a3<=x && b2<=y && b3<=y)return true;
    if(a2+b3<=x && b2<=y && a3<=y)return true;
    if(b2+a3<=x && a2<=y && b3<=y)return true;
    if(b2+b3<=x && a2<=y && a3<=y)return true;
    return false;
}
int main() 
{
    int x,y;
 
    cin>>x>>y>>a2>>b2>>a3>>b3;
    if(f(x,y) || f(y,x))cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}