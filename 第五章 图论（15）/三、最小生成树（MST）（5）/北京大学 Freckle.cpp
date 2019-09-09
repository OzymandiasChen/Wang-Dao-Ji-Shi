#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int Tree[101];

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

struct edge
{
	int a,b;
	double cost;
	bool operator <(const edge &A)
	{
		return (cost<A.cost)?true:false;
	}
}Edge[10000];

struct point
{
	double x,y;
	double GetCost(point A)
	{
		double tmp=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
		return sqrt(tmp);
	}
}Point[101];

int size;

int main()
{
	int n;
	int i,j;
	int a,b;
	double ans;
	while(scanf("%d",&n)!=EOF)
	{
		size=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf %lf",&Point[i].x,&Point[i].y);
			Tree[i]=-1;
		}
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			{
				Edge[size].a=i;
				Edge[size].b=j;
				Edge[size].cost=Point[i].GetCost(Point[j]);
				size++;
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
		printf("%.2lf\n",ans);
	}
	return 0;
}
