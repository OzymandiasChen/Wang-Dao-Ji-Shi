#include <stdio.h>

/////////false表示为素数
bool buf[10001];
int prime[10000];
int primesize=0;
void init()
{
	int i,j;
	for(i=0;i<10001;i++)
		buf[i]=false;

	for(i=2;i<10001;i++)
		if(buf[i]==false)
		{
			prime[primesize++]=i;
			for(j=i*i;j<10001;j+=i)
					buf[j]=true;
		}

}

int main()
{
	init();

	bool flag=false;
	int n;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		i=0;
		flag=false;
		while(i<primesize&&prime[i]<n)
		{
			if(prime[i]%10==1)
				if(flag)
					printf(" %d",prime[i]);
				else
				{
					flag=true;
					printf("%d",prime[i]);
				}
			i++;
		}
		if(flag==false)
			printf("-1\n");
		else
			printf("\n");
	}
	return 0;
}
