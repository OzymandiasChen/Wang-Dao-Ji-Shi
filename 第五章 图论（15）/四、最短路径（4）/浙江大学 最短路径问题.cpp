#include <stdio.h>
#include <vector>
using namespace std;

struct E
{
	int next;
	int cost;
	int P;
};
vector<E> Edge[1001];///邻接链表
bool mark[1001];
int dis[1001];
int cost[1001];

int main()
{
	int N,M;
	int i,j;
	int A,B,D,P;
	int newP;
	int tmp;
	int c;
	int min;
	int s,t;
	while(scanf("%d %d",&N,&M)!=EOF&&M!=0&&N!=0)
	{
		for(i=1;i<=N;i++)
		{
			dis[i]=-1;
			mark[i]=false;
			Edge[i].clear();
            cost[i]=0;
		}
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d %d",&A,&B,&D,&P);
            E ttt;
			ttt.cost=D;
			ttt.next=A;
			ttt.P=P;
			Edge[B].push_back(ttt);
			ttt.next=B;
			Edge[A].push_back(ttt);
		}
		scanf("%d %d",&s,&t);
		dis[s]=0;
		mark[s]=true;
        cost[s]=0;
		newP=s;
		for(i=1;i<N;i++)
		{
			for(j=0;j<Edge[newP].size();j++)
			{
				tmp=Edge[newP][j].next;
				c=Edge[newP][j].cost;
				P=Edge[newP][j].P;
				if(mark[tmp]==true)
					continue;
				if(dis[tmp]==-1||dis[newP]+c<dis[tmp]||(dis[newP]+c==dis[tmp]&&cost[newP]+P<cost[tmp]))
				{
					dis[tmp]=dis[newP]+c;
					cost[tmp]=cost[newP]+P;
				}
			}
			min=123123123;
			for(j=1;j<=N;j++)
				if(mark[j]==false&&dis[j]!=-1)
					if(dis[j]<min)
					{
						min=dis[j];
						newP=j;
					}
			mark[newP]=true;
		}
		printf("%d %d\n",dis[t],cost[t]);
	}
	return 0;
}
