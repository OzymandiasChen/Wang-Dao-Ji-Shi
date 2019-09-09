#include <stdio.h>////T就是背包
struct E
{
	int V;
	int T;
}list[101];
int dp[101][1001];

int main()
{
	int T,M;
	int i,j;
	int tmp;
	while(scanf("%d %d",&T,&M)!=EOF)
	{
		for(i=1;i<=M;i++)
			scanf("%d %d",&list[i].T,&list[i].V);
		for(i=0;i<=T;i++)
			dp[0][i]=0;
		for(i=1;i<=M;i++)
		{
			for(j=T;j>=list[i].T;j--)
			{
				tmp=dp[i-1][j-list[i].T]+list[i].V;///list[i]装没装
				dp[i][j]=tmp>dp[i-1][j]?tmp:dp[i-1][j];
			}
			for(j=list[i].T-1;j>=0;j--)///list[i]肯定装不了
				dp[i][j]=dp[i-1][j];
		}
		printf("%d\n",dp[M][T]);
	}
	return 0;
}
