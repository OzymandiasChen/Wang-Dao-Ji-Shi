#include <stdio.h>
#define MAX 10000

int ans[101][101];

int main()
{
	int M,N;
	int i,j,k;
	int A,B,C;
	while(scanf("%d %d",&N,&M)!=EOF&&M!=0&&N!=0)
	{
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
				ans[i][j]=10000;
			ans[i][i]=0;
		}
		for(k=0;k<M;k++)
		{
			scanf("%d %d %d",&A,&B,&C);
			ans[A][B]=C;
			ans[B][A]=C;
		}
		for(k=1;k<=N;k++)
		{
			for(i=1;i<=N;i++)
				for(j=1;j<=N;j++)
					if(ans[i][k]+ans[k][j]<ans[i][j])
						ans[i][j]=ans[i][k]+ans[k][j];
		}
		printf("%d\n",ans[1][N]);
	}
	return 0;
}
