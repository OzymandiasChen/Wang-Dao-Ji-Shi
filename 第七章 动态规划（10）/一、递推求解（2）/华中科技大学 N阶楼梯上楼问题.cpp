#include <stdio.h>
long long F[90];

int main()
{
	int N;
	F[1]=1;
	F[2]=2;
	for(int i=3;i<90;i++)
		F[i]=F[i-1]+F[i-2];
	while(scanf("%d",&N)!=EOF)
		printf("%lld\n",F[N]);
	return 0;
}