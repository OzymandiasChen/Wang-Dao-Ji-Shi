//2018.01.08 17:45-18:15
#include <stdio.h>

int N[201]={0},M[201]={0};

int main()
{
	int n,m;
	int i;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&N[i]);
			M[N[i]]++;
		}
		for(i=1;i<=n;i++)
			if(M[N[i]]>1)
				printf("%d\n",M[N[i]]-1);
			else
				printf("BeiJu\n");
		for(i=1;i<=200;i++)
			M[i]=0;
	}
	return 0;
}
