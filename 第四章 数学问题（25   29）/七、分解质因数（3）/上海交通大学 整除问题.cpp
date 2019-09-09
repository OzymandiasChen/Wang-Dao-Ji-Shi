#include <stdio.h>

bool mark[1001];
int prime[1001];
int primesize=0;

void init()
{
		int i,j;
	for(i=0;i<1001;i++)
		mark[i]=false;
	for(i=2;i<1001;i++)
		if(mark[i]==false)
		{
			for(j=i*i;j<1001;j+=i)
				mark[j]=true;
			prime[primesize++]=i;
		}
}

int main()
{
	init();
	int n,a,ans;
	int i;
	int cnt1[1001];
	int cnt2[1001];
	int p,t;
	while(scanf("%d %d",&n,&a)!=EOF)
	{
		for(i=0;i<1001;i++)
			cnt1[i]=0;
		ans=123123123;
		for(i=0;prime[i]<=n;i++)
		{
			p=prime[i];
			while(n/p)
			{
				cnt1[i]+=n/p;
				p*=prime[i];
			}
		}
		for(i=0;i<1001;i++)
			cnt2[i]=0;
		t=a;
		for(i=0;prime[i]<=a;i++)
		{
			while(t%prime[i]==0)
			{
				cnt2[i]++;
				t/=prime[i];
			}
			if(cnt2[i]!=0)
				if(cnt1[i]/cnt2[i]<ans)
					ans=cnt1[i]/cnt2[i];

		}
		printf("%d\n",ans);
	}
	return 0;
}