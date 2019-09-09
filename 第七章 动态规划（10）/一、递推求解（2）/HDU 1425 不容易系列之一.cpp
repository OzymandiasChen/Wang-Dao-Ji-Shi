#include <stdio.h>

int main()
{
	long long F[21];
	int n;
	int i;
	F[1]=0;
	F[2]=1;
	for(i=3;i<=20;i++)
		F[i]=(i-1)*(F[i-1]+F[i-2]);
	while(scanf("%d",&n)!=EOF)
		printf("%lld\n",F[n]);
	return 0;
}
