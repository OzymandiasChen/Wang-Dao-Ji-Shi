#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

struct E
{
	int next;
	long long cost;
};
vector<E> Edge[300];///邻接链表
bool mark[300];
long long dis[300];

int main()
{
	int N,M;
	int i,j;
	int A,B;
	int newP;
	int tmp;
	long long c,q;
	long long mine;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			dis[i]=-1;
			mark[i]=false;
			Edge[i].clear();
		}
		q=1;
		for(i=0;i<M;i++)
		{
			scanf("%d %d",&A,&B);
			E ttt;
			ttt.cost=q;
			ttt.next=A;
			Edge[B].push_back(ttt);
			ttt.next=B;
			Edge[A].push_back(ttt);
			q*=2;
		}
		dis[0]=0;
		mark[0]=true;
		newP=0;
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
			mine=9223372036854775807;
			for(j=0;j<N;j++)
				if(mark[j]==false&&dis[j]!=-1)
				{
					if(dis[j]<mine)
					{
						mine=dis[j];
						newP=j;
					}
				}
			mark[newP]=true;
		}
		for(i=1;i<N;i++)
			printf("%lld\n",dis[i]%100000);
	}
	return 0;
}
