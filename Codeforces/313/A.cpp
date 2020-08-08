#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))

typedef long long ll;

using namespace std;

int main () {
	int n;
	cin >> n;
	int Max = n;
	if (n/10 > Max) Max = n/10;
	if (n%10 + (n/100)*10 > Max) Max = n%10 + (n/100)*10;
	cout << Max;
}