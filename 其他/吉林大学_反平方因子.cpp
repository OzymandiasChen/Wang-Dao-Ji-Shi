#include <stdio.h>

int main ()
{
	int n;
	int i;
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		if(n==0)
			break;
		for(i=2;i<100;i++)
			if(!(n%(i*i)))
			{
				flag=1;
				break;
			}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}