#include <stdio.h>

int main()
{
	int n;
	int x,y,z;
	while(scanf("%d",&n)!=EOF)
	{
		for(x=0;x<=100;x++)
			for(y=0;y<=100;y++)
			{
				z=100-x-y;
				if(x*5*3+y*3*3+z*1<=n*3)
					printf("x=%d,y=%d,z=%d\n",x,y,z);
			}
	}
	return 0;
}