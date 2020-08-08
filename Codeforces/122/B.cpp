#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define mp make_pair
#define pb push_back 
//#define m 1000000007
 
int main()
{
  string s;
  cin>>s;
int f=0,c=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='4')
        f++;
    if(s[i]=='7')
        c++;
  }
 
if(f==0 && c==0)
{
    cout<<"-1";
    return 0;
}
if(f>=c)
{
    cout<<"4";
    return 0;
}
  if(f<c)
  {
    cout<<"7";
  }
  }