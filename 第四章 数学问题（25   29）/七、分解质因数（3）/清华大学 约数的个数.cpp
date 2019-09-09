#include <stdio.h>
#define M 100001


bool mark[M];
int prime[M];
int primesize=0;

void init()
{
	int i,j;
	for(i=0;i<M;i++)
		mark[i]=false;
	for(i=2;i<M;i++)
		if(mark[i]==false)
        {
            for(j=i*i;j<M;j+=i)
				mark[j]=true;
			prime[primesize++]=i;
        }
}

int main()
{
	init();
	int i,j;
	int n;
	int ans[1001];
	int tmp,a;
	int id;
	int k;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            a=tmp;
            id=0;
            for(j=0;j<primesize;j++)
            {
                if(a%prime[j]==0)
                {
                    ans[id]=0;
                    while(a%prime[j]==0)
                    {
                        ans[id]++;
                        a/=prime[j];
                    }
                    id++;
                }
                if(a==1)
                    break;
            }

            if(a!=1)
                ans[id++]=1;
            k=1;
            for(j=0;j<id;j++)
                k*=(ans[j]+1);
            printf("%d\n",k);
        }
    }
	
	return 0;
}
