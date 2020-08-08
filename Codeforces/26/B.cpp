#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  string s;
  cin>>s;
  stack<char> a;
  ll l=s.length();
  for(ll i=0;i<l;i++)
  {
  	if(a.empty())
  	{
  		a.push(s[i]);
  	}
  	else if(s[i]==')')
  	{
  		if(a.top()=='(')
  		{
  			a.pop();
  		}
  		else
  		{
  			a.push(s[i]);
  		}
  	}
  	else
  	{
  		a.push(s[i]);
  	}
  }
  cout<<l-a.size()<<endl;
}