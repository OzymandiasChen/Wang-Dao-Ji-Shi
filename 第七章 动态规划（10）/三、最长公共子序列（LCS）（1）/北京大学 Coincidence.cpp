#include  <stdio.h>
#include <string.h>
char S1[200],S2[200];
int dp[200][200];

int main()
{
	int i,j;
	int L1,L2;
	while(scanf("%s%s",S1,S2)!=EOF)
	{
		L1=strlen(S1);
		L2=strlen(S2);
		for(i=0;i<=L1;i++)
			dp[i][0]=0;
		for(i=0;i<=L2;i++)
			dp[0][i]=0;
		for(i=1;i<=L1;i++)
			for(j=1;j<=L2;j++)
				if(S1[i-1]==S2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=dp[i][j-1]>dp[i-1][j]?dp[i][j-1]:dp[i-1][j];
		printf("%d\n",dp[L1][L2]);
	}
	return 0;
}
