#include <stdio.h>

int main()
{
	int n;
	int x,y,z;
	int i,j;
	int a,b,c,d;
	int tmp;
	int flag;
	while(scanf("%d%d%d%d",&n,&x,&y,&z)!=EOF)
	{
		flag=false;
		for(j=99999;j>0;j--)
		{
			tmp=j*n;
            d=tmp/10000;
			a=(tmp/1000)%10;
			b=(tmp/100)%10;
			c=(tmp/10)%10;
			if(d>0&&d<10&&a==x&&b==y&&c==z)
			{
				flag=true;
				printf("%d %d %d\n",tmp/10000,tmp%10,j);
				break;
			}
		}
		if(!flag)
			printf("0\n");
	}
	return 0;
}
