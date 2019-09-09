///2017.01.09 19:39-19:54
#include <stdio.h>
#define OFFSET 500000

int main()
{
	int n,m;
	int tmp;
	int i;
	int buf[1000001];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<1000001;i++)
			buf[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			buf[tmp+OFFSET]=1;
		}
		i=1000001;
		while(--m)
		{
			while(buf[--i]!=1);
			printf("%d ",i-OFFSET);
		}
		while(buf[--i]!=1);
			printf("%d\n",i-OFFSET);
	}
	return 0;
		
}