#include <stdio.h>
#include <vector>
using namespace std;

struct E
{
	int next;
	int cost;
}e[10000];
vector<E> Edge[101];///邻接链表
bool mark[101];
int dis[101];
int size;

int main()
{
	int N,M;
	int i,j;
	int A,B,C;
	int newP;
	int tmp;
	int c;
	int min;
	while(scanf("%d %d",&N,&M)!=EOF&&M!=0&&N!=0)
	{
		for(i=1;i<=N;i++)
		{
			dis[i]=-1;
			mark[i]=false;
			Edge[i].clear();
		}
		size=0;
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d",&A,&B,&C);
			e[size].cost=C;
			e[size].next=A;
			Edge[B].push_back(e[size]);
			size++;
			e[size].cost=C;
			e[size].next=B;
			Edge[A].push_back(e[size]);
			size++;
		}
		dis[1]=0;
		mark[1]=true;
		newP=1;
		for(i=1;i<N;i++)
		{
			for(j=0;j<Edge[newP].size();j++)
			{
				tmp=Edge[newP][j].next;
				c=Edge[newP][j].cost;
				if(mark[tmp]==true)
					continue;
				if(dis[tmp]==-1||dis[newP]+c<dis[tmp])
					dis[tmp]=dis[newP]+c;
			}
			min=123123123;
			for(j=1;j<=N;j++)
				if(mark[j]==false&&dis[j]!=-1)
				{
					if(dis[j]<min)
					{
						min=dis[j];
						newP=j;
					}
				}
			mark[newP]=true;
		}
		printf("%d\n",dis[N]);
	}
	return 0;
}
