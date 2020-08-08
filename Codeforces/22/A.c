#include<stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b)
{
	return (*(int *)a -*(int *)b);
}
int main()
{
	int t,min,min1;
	scanf("%d",&t);
	int arr[t];
	for(int i=0;i<t;i++)
		scanf("%d",&arr[i]);
	qsort(arr,t,sizeof(int),compare);
	min = arr[0];
	min1 = arr[0];
	for(int i=1;i<t;i++)
	{
		if(arr[i]!=min)
			{
				min = arr[i];
				break;
			}
	}
	if(min==min1)
		printf("NO\n");
	else
	printf("%d\n",min);
}