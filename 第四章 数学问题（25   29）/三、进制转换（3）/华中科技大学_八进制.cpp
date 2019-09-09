#include <stdio.h>

int main()
{
	int n;
	int ans[100];
	int i,size;
	while(scanf("%d",&n)!=EOF)
	{
		size=0;
		do
		{
			ans[size++]=n%8;
			n/=8;
		}
		while(n);
		for(i=size-1;i>=0;i--)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}