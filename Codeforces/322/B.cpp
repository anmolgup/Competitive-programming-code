#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long int r,g,b;
  cin>>r>>g>>b;
  long long int ans=r/3+g/3+b/3;
  if(r>1&&b>1&&g>1)
  {
    ans=max(ans,2+(r-2)/3+(g-2)/3+(b-2)/3);
    ans=max(ans,1+(r-1)/3+(g-1)/3+(b-1)/3);
  }
  if(r>0&&b>0&&g>0)
    ans=max(ans,1+(r-1)/3+(g-1)/3+(b-1)/3);
  cout<<ans;
  return 0;
}