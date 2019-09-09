#include <stdio.h>
#define INF 0x7fffffff///一定要有无效状态
struct E
{
	int P;
	int W;
}list[501];
int dp[10001];

int main()
{
	int T;
	int i,j;
	int E,F;
	int N;
	int tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&E,&F);
		F-=E;
		scanf("%d",&N);
		for(i=1;i<=N;i++)
			scanf("%d %d",&list[i].P,&list[i].W);
		for(i=1;i<=F;i++)
			dp[i]=INF;////背包容量为i，却没有东西装是不可能有的状况
		dp[0]=0;
		for(i=1;i<=N;i++)
			for(j=list[i].W;j<=F;j++)
				if(dp[j-list[i].W]!=INF)
				{
					tmp=dp[j-list[i].W]+list[i].P;
					dp[j]=tmp<dp[j]?tmp:dp[j];
				}
		if(dp[F]!=INF)
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[F]);
		else
			printf("This is impossible.\n");
	}
	return 0;
}
