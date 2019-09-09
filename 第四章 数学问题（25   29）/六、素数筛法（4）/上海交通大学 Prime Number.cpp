#include <stdio.h>
#define MAX 100000

/////false为素数

bool mark[MAX];
int prime[10001];
int primesize=1;

void init()
{
	bool flag;
	int i,j;
	for(i=0;i<MAX;i++)
		mark[i]=false;
	i=2;
	while(primesize<10001)
	{
		if(mark[i]==false)
		{
			for(j=i*i;j<MAX;j+=i)
				mark[j]=true;
			prime[primesize++]=i;
		}
		i++;
	}
}

int main()
{
	init();
	int k;
	while(scanf("%d",&k)!=EOF)
		printf("%d\n",prime[k]);
	return 0;
}