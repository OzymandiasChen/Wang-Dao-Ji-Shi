#include <stdio.h>

int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		while(x!=y)
		{
			if(x>y)
				x/=2;
			else if(y>x)
				y/=2;
		}
		printf("%d\n",x);
	}
	return 0;
}