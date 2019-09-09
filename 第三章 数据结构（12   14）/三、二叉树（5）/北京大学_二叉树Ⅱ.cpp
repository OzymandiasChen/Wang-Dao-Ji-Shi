#include <stdio.h>

int count(int x,int y)
{
	if(y>x)
		return 0;
	else 
		return count(x,y*2)+count(x,y*2+1)+1;
}

int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		if(y==0&&y==0)
			break;
		printf("%d\n",count(y,x));
	}
	return 0;
}