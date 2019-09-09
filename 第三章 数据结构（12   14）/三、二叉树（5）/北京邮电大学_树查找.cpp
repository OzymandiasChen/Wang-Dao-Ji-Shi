#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	int i;
	int d;
	int s[1010];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		scanf("%d",&d);
		if(pow(2,d-1)<=n)
		{
			if(pow(2,d)-1<=n)
			{
				for(i=(int)pow(2,d-1);i<(int)pow(2,d)-1;i++)
					printf("%d ",s[i]);
				printf("%d\n",s[i]);
			}
			else
			{
				for(i=(int)pow(2,d-1);i<n;i++)
					printf("%d ",s[i]);
				printf("%d\n",s[i]);
			}
		}
		else
			printf("EMPTY\n");
	}
	return 0;
}