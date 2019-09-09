#include <stdio.h>
#include <algorithm>
using namespace std;

int Tree[101];
struct edge
{
	int a,b;
	int dis;
	bool operator < (const edge &A)
	{
		return dis<A.dis?true:false;
	}
}Edge[10001];

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
	int n,N;
	int i;
	int a,b;
	int ans;
	while(scanf("%d",&N)!=EOF&&N!=0)
	{
		for(i=1;i<=N;i++)
			Tree[i]=-1;
		n=N*(N-1)/2;
		for(i=0;i<n;i++)
			scanf("%d %d %d",&Edge[i].a,&Edge[i].b,&Edge[i].dis);
		sort(Edge,Edge+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			a=FindRoot(Edge[i].a);
			b=FindRoot(Edge[i].b);
			if(a!=b)
            {
                ans+=Edge[i].dis;
                Tree[a]=b;
            }
		}
		printf("%d\n",ans);

	}
	return 0;
}