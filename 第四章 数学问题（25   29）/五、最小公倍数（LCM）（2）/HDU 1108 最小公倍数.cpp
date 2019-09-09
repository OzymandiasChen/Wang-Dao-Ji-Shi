#include <stdio.h>

int gcb(int a,int b)
{
	return (b==0)?a:gcb(b,a%b);
}
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		int n=gcb(a,b);
		printf("%d\n",a*b/n);
	}
	return 0;
}