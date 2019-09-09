#include <stdio.h>
#define N 100001

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

int Sum[N];

int main()
{
	int a,b;
	int n;
	int ans;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<N;i++)
		{
			Sum[i]=1;
			Tree[i]=-1;
		}
		ans=0;
		while(n--)
		{
			scanf("%d %d",&a,&b);
			a=FindRoot(a);
			b=FindRoot(b);
			if(a!=b)
			{
				Tree[a]=b;
				Sum[b]+=Sum[a];
			}
		}
		for(i=1;i<N;i++)
			if(Tree[i]==-1&&Sum[i]>ans)
				ans=Sum[i];
		printf("%d\n",ans);
	}
	return 0;
}