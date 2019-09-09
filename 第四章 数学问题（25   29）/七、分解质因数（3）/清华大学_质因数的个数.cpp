#include <stdio.h>
#define MAX 100001


bool mark[MAX];
int prime[MAX];
int primesize=0;

void init()
{
	int i,j;
	for(i=0;i<MAX;i++)
		mark[i]=false;
	for(i=2;i<MAX;i++)
		if(mark[i]==false)
        {
            for(j=i*i;j<MAX;j+=i)
				mark[j]=true;
			prime[primesize++]=i;
        }
}

int main()
{
	init();
	int n;
	int i,j,anssize;
	int p[MAX],e[MAX];
	int ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		anssize=0;
		for(i=0;i<primesize;i++)
			if(n%prime[i]==0)
			{
				p[anssize]=prime[i];
				e[anssize]=0;
				while(n%prime[i]==0)
				{
					e[anssize]++;
					n/=prime[i];
				}

				anssize++;
				if(n==1)
					break;
			}
		if(n!=1)
		{
			p[anssize]=n;
			e[anssize]=1;
			anssize++;
		}
		for(i=0;i<anssize;i++)
			ans+=e[i];
		printf("%d\n",ans);
	}
	return 0;
}