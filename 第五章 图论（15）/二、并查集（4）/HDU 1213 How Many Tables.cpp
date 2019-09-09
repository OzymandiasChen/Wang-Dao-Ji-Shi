#include <stdio.h>
#define N 1001

int Tree[N];

int FindRoot(int x)
{
	int tmp;
	if(Tree[x]==-1)
		return x;
	else
	{
		tmp=FindRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

int main()
{
	int m,n;
	int i;
	int ans;
	int a,b;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		ans=0;
		for(i=1;i<=n;i++)
			Tree[i]=-1;
		while(m--)
		{
			scanf("%d %d",&a,&b);
			a=FindRoot(a);
			b=FindRoot(b);
			if(a!=b)
				Tree[a]=b;
		}
		for(i=1;i<=n;i++)
			if(Tree[i]==-1)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}