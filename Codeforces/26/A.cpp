#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef vector<string> VS;
 
 
#define ST          first
#define ND          second
#define ALL(x)      (x).begin(), (x).end()
#define FOR(i,s,n)  for(i=s;i<(n);++i)
#define REP(i,s,n)  for(i=s;i<=(n);++i)
#define LOOP(i,x)   for(i=0;i<SZ(x);++i)
#define IT(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define PB          push_back
#define MP          make_pair
#define SZ(x)       (int)(x.size())
#define DISP(x)     cout << #x << ": " << x << endl;
 
int calc(int x)
{
	int ret = 0, i;
 
	for(i = 2; i * i <= x; ++i)
	{
		if(x % i == 0)
		{
			while(x % i == 0)
			{
				x /= i;
			}
			++ret;
		}
	}
	if(x > 1) ++ret;
 
	return ret;
}
int main()
{
    int i,j, n, cnt = 0;
	scanf("%d", &n);
	for(i = 2; i <= n; ++i)
	{
		if(calc(i) == 2) ++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}