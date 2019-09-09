//2018.01.09 20:30-
#include <stdio.h>

int main()
{
	char buf[81][81];
	int n;
	char a,b,c;
	int i;
	int x0,y0,x,y;
    int cnt=1;
	while(scanf("%d %c %c",&n,&a,&b)!=EOF)
	{
        if(cnt!=1)
            printf("\n");
		x0=n/2+1;
		y0=n/2+1;
		for(i=0;i<n/2+1;i++)
		{
			if(i%2==0)
				c=a;
			else
				c=b;
			for(x=x0-i;x<=x0+i;x++)
			{
				buf[x][y0-i]=c;
				buf[x][y0+i]=c;
			}
			for(y=y0-i;y<=y0+i;y++)
			{
				buf[x0-i][y]=c;
				buf[x0+i][y]=c;
			}
		}
        if(n!=1)
        {
            buf[1][1]=' '; 
			buf[1][n]=' ';
			buf[n][1]=' ';
			buf[n][n]=' ';
        }
		for(x=1;x<=n;x++)
			for(y=1;y<=n;y++)
			{
				printf("%c",buf[x][y]);
				if(y==n)
					printf("\n");
			}
		cnt++;
	}
	return 0;
}