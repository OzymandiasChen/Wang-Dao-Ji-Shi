#include <stdio.h>
#include <algorithm>
using namespace std;

int n,k;
int dp[2001][2001];
int list[2001];

int main()
{
	int i,j;
	int tmp;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&list[i]);
		sort(list+1,list+n+1);
		for(i=0;i<=n;i++)
			dp[0][i]=0;
		for(i=0;i<=k;i++)
			dp[i][0]=0;
		for(i=1;i<=k;i++)
			for(j=2*i;j<=n;j++)
			{
				tmp=dp[i-1][j-2]+(list[j]-list[j-1])*(list[j]-list[j-1]);
				if(j==i*2)
					dp[i][j]=tmp;
				else
					dp[i][j]=(dp[i][j-1]<tmp?dp[i][j-1]:tmp);
			}
		printf("%d\n",dp[k][n]);
	}
	return 0;
}
