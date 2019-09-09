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
}Edge[101];

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
	int M,N;
	int i;
	int a,b;
	int ans;
	int cnt;
	while(scanf("%d %d",&N,&M)!=EOF&&N!=0)
	{
		for(i=1;i<=M;i++)
			Tree[i]=-1;
		for(i=0;i<N;i++)
			scanf("%d %d %d",&Edge[i].a,&Edge[i].b,&Edge[i].dis);
		sort(Edge,Edge+N);
		ans=0;
		for(i=0;i<N;i++)
		{
			a=FindRoot(Edge[i].a);
			b=FindRoot(Edge[i].b);
			if(a!=b)
            {
                ans+=Edge[i].dis;
                Tree[a]=b;
            }
		}
		cnt=0;
		for(i=1;i<=M;i++)
			if(Tree[i]==-1)
				cnt++;
		if(cnt==1)
			printf("%d\n",ans);
		else
			printf("?\n");

	}
	return 0;
}