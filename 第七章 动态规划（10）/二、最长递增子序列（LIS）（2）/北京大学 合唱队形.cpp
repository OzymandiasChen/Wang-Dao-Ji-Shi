#include <stdio.h>
int list[101];
int dp[101];//降序disendent
int ap[101];//升序ascendent

int main()
{
	int i,j;
	int n;
	int max;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&list[i]);
		dp[n]=1;
		ap[1]=1;
		for(i=1;i<=n;i++)
		{
			max=1;
			for(j=1;j<i;j++)
				if(list[i]>list[j])
					max=(ap[j]+1>max?ap[j]+1:max);
			ap[i]=max;
		}
		for(i=n-1;i>=1;i--)
		{
			max=1;
			for(j=n;j>i;j--)
				if(list[i]>list[j])
					max=(dp[j]+1>max?dp[j]+1:max);
			dp[i]=max;
		}
		max=0;
		for(i=1;i<=n;i++)
			max=(dp[i]+ap[i]-1>max?dp[i]+ap[i]-1:max);
		printf("%d\n",n-max);
	}
	return 0;
}