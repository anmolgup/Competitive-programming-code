#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b);
int main(void)
{
	int y, w, n, i, num, den;
	scanf("%d %d", &y, &w);
	num=7-max(y, w);
	den=6;
	i=gcd(num, den);
	while(i!=1)
	{
		num=num/i;
		den=den/i;
		i=gcd(num, den);
	}
	printf("%d/%d\n", num, den);
	return 0;
}
int gcd(int a, int b)
{
	if(a==0)
	{
		return b;
	}
	return gcd(b%a, a);
}