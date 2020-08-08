#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
 int t,n,count;
 scanf("%d",&t);
 while(t--)
 {
 count=0;
 scanf("%d",&n);
 while(n>=5)
 {
 count += n/5;
 n /= 5;
 }
 printf("%d\n",count);
 }
 return 0;
