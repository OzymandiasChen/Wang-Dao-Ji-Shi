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

int FindRoot(int x)/////联动
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

int size;

int main()
{
	int n,N;
	int i;
	int a,b,dis,flag;
	int ans;
	while(scanf("%d",&N)!=EOF&&N!=0)
	{
		for(i=1;i<=N;i++)
			Tree[i]=-1;
		n=N*(N-1)/2;
		size=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&a,&b,&dis,&flag);
			if(flag==0)
			{
				Edge[size].a=a;
				Edge[size].b=b;
				Edge[size].dis=dis;
				size++;
			}
			if(flag==1)
			{
				a=FindRoot(a);
				b=FindRoot(b);
				if(a!=b)
	                Tree[a]=b;
			}
		}
		sort(Edge,Edge+size);
		ans=0;
		for(i=0;i<size;i++)
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