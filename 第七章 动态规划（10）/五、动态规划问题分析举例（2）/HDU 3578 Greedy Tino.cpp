#include <stdio.h>
#define offset 2000

int list[101];
int dp[101][4001];////看到第i个，左比右大j时的最大重量

int main()
{
	int T;
	int i,j;
	int n;
	int Case;
	int cnt;
	int max;
	int tmp;
	scanf("%d",&T);
	for(Case=1;Case<=T;Case++)
	{
		cnt=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
			if(list[i]==0)
				cnt++;///考虑到有重量为0的橘子
		}
		for(i=-offset;i<=offset;i++)
			dp[0][i+offset]=-1;///无效点
			dp[0][0+offset]=0;
		for(i=1;i<=n;i++)
			for(j=-offset;j<=offset;j++)
			{
				max=-1;
				if(j-list[i]>=-offset&&dp[i-1][j-list[i]+offset]!=-1)///往右放
				{
					tmp=dp[i-1][j-list[i]+offset]+list[i];
					max=tmp>max?tmp:max;
				}
				if(j+list[i]<=offset&&dp[i-1][j+list[i]+offset]!=-1)///往左放
				{
					tmp=dp[i-1][j+list[i]+offset]+list[i];
					max=tmp>max?tmp:max;
				}
				if(dp[i-1][j+offset]!=-1)///不作为
				{
					tmp=dp[i-1][j+offset];
					max=tmp>max?tmp:max;
				}
				dp[i][j+offset]=max;
			}
		if(cnt==0&&dp[n][0+offset]==0)
			printf("Case %d: -1\n",Case);
		else
			printf("Case %d: %d\n",Case,dp[n][0+offset]/2);
	}
	return 0;
}
