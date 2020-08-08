#include <bits/stdc++.h>
using namespace std;
int a[111],b[6];
int main()
{
	printf("? 1 2");
	cout<<endl;
	scanf("%d",&a[1]);
	printf("? 3 4");
	cout<<endl;
	scanf("%d",&a[2]);
	cout<<endl;
	fflush(stdout);
	cout<<endl;
	printf("? 5 5");
	cout<<endl;
	scanf("%d",&a[4]);
	b[0]=4,b[1]=8,b[2]=15,b[3]=16,b[4]=23,b[5]=42;
	do
	{
		if(b[0]*b[1]==a[1]&&b[2]*b[3]==a[2]&&b[0]*b[2]==a[3]&&b[4]*b[4]==a[4])
		{
			printf("! %d %d %d %d %d %d",b[0],b[1],b[2],b[3],b[4],b[5]);
			break;
		}
	}while(next_permutation(b,b+6));
	return 0;
}