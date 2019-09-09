#include <stdio.h>

int gcb(int a,int b)
{
	if(b==0)
		return a;
	return gcb(b,a%b);
}

int main()
{
	int a,b;
	int n;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		n=gcb(a,b);
		printf("%d\n",n);
	}
	return 0;
}