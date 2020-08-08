#include <stdio.h>
//#include <stdlib.h>
int main()
{
	int d,sum;
	scanf("%d %d ",&d,&sum);
	int lower[d],upper[d],limit[d],extra,sum1,sum2,diff;
	extra =0;
	sum1 =0;
	sum2 =0;
	for(int i=0;i<d;i++)
	{
		scanf("%d %d ",&lower[i],&upper[i]);
		sum1 += lower[i];
		sum2 += upper[i];
		limit[i] = lower[i]; 
	}
	extra = sum - sum1;
	if(sum>=sum1&&sum<=sum2)
		{
			printf("YES\n");
			for(int i=0;i<d;i++)
			{
				if(extra<0)
					break;
				diff = upper[i] - lower[i];
				limit[i] += ((extra<diff)?extra:diff);
				extra -= diff;
			}	
			for(int i=0;i<d;i++)
		printf("%d ",limit[i]);
		}
	else
	{	
		printf("NO\n");
	}
}