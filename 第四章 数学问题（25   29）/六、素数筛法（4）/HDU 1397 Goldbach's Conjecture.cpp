#include <stdio.h>
#define M 40000
////2^15=32768
////false 为素数

bool mark[M];
void init()
{
	int i,j;
	for(i=0;i<M;i++)
		mark[i]=false;
	for(i=2;i<M;i++)
		if(mark[i]==false)
			for(j=i*i;j<M;j+=i)
				mark[j]=true;
}

int main()
{
	init();
	int n;
	int i;
	int ans;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		ans=0;
		for(i=2;i<=n/2;i++)
            if(!mark[n-i]&&!mark[i]) 
                ans++;
		printf("%d\n",ans);
	}
	return 0;
}