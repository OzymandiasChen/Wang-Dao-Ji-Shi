#include <stdio.h>

long long F(int k)
{
	if(k==1)
		return 2;
	else
		return 3*F(k-1)+2;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",F(n));
	}
	return 0;
}
