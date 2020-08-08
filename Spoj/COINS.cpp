#include<bits/stdc++.h>

using namespace std;

map <int , long long> h;

long long f(long long n) //precondition -> h.clear() 
{
  if (n == 0) return 0; //base

  long long r = h[n];

  if (r == 0) 
  {
    r = max( n , f(n/2)+f(n/3)+f(n/4) );
    h[n] = r;
  }

  return r;
}
int main()
{
    long long n;
    while(cin >> n)
    {
        h.clear();
        cout<<f(n)<<endl;
    }
