#include <stdio.h>

int dp[101];
struct E
{
	int p;
	int h;
}list[2001];

int main()
{
	int i,j;
	int C;
	int n,m;
	int cnt;
	int p,h,c;
	int q;
	int tmp;
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d %d",&n,&m);
		cnt=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d %d",&p,&h,&c);
			q=1;
			while(c-q>0)
			{
				c-=q;
				list[++cnt].p=p*q;
				list[cnt].h=h*q;
				q*=2;
			}
			list[++cnt].p=p*c;
			list[cnt].h=h*c;
		}
		for(i=0;i<=n;i++)
			dp[i]=0;///标记无效
		for(i=1;i<=cnt;i++)
			for(j=n;j>=0;j--)
				if(j-list[i].p>=0)
				{
					tmp=dp[j-list[i].p]+list[i].h;
					dp[j]=tmp>dp[j]?tmp:dp[j];
				}
		printf("%d\n",dp[n]);
	}
	return 0;
}
