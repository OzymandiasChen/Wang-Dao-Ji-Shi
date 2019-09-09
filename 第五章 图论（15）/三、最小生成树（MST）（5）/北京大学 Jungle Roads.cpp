#include <stdio.h>
#include <algorithm>
using namespace std;

int Tree[101];

char FindRoot(char x)
{
	char tmp;
	if(Tree[x]==-1)
		return x;
	else
	{
		tmp=FindRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

struct edge
{
	char a,b;
	int cost;
	bool operator <(const edge &A)
	{
		return (cost<A.cost)?true:false;
	}
}Edge[1000];

int size;

int main()
{
	int n;
	int i,j,k;
	char tmp;
	char ch;
	char a,b;
	int ans;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
        scanf("%c",&ch);
		for(i='A';i<'A'+n;i++)
			Tree[i]=-1;
		size=0;
		for(i=1;i<n;i++)
		{
			scanf("%c %d ",&tmp,&k);
			for(j=0;j<k;j++)
			{
				Edge[size].a=tmp;
				scanf("%c %d%c",&Edge[size].b,&Edge[size].cost,&ch);
				size++;
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
				Tree[a]=b;
				ans+=Edge[i].cost;
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}
