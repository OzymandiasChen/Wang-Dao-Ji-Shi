//2018 01.08 18:20-18:38
#include <stdio.h>

int main()
{
	int Road[10001];
	int L,M,b,e;
	int i,j;
	int cnt;
	while(scanf("%d%d",&L,&M)!=EOF)
	{
		for(i=0;i<=L;i++)
			Road[i]=1;
		while(M--)
		{
			scanf("%d%d",&b,&e);
			for(i=b;i<=e;i++)
				Road[i]=0;
		}
		cnt=0;
		for(i=0;i<=L;i++)
			cnt+=Road[i];
        
		printf("%d\n",cnt);

	}

	return 0;
}