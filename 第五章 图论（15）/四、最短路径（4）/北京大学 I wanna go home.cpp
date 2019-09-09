#include <stdio.h>
#include <vector>
using namespace std;

struct E
{
	int next;
	int cost;
};
vector<E> Edge[601];///邻接链表
bool mark[601];
int lable[601];
int dis[601];
int size;
int A[10000],B[10000],T[10000];

int main()
{
	int N,M;
	int i,j;
	int newP;
	int tmp;
	int c;
	int min;
	while(scanf("%d",&N)!=EOF&&N!=0)
	{
		scanf("%d",&M);
		for(i=1;i<=N;i++)
		{
			dis[i]=-1;
			mark[i]=false;
			Edge[i].clear();
		}
		size=0;
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d",&A[i],&B[i],&T[i]);
		}
		for(i=1;i<=N;i++)
			scanf("%d",&lable[i]);
		for(i=0;i<M;i++)
		{
			E ttt;
			if(lable[A[i]]==lable[B[i]])
			{
				ttt.next=B[i];
				ttt.cost=T[i];
				Edge[A[i]].push_back(ttt);
				ttt.next=A[i];
				Edge[B[i]].push_back(ttt);
			}
			else
			{
				if(lable[A[i]]==1)
				{
					ttt.next=B[i];
					ttt.cost=T[i];
					Edge[A[i]].push_back(ttt);
				}
				else
				{
					ttt.next=A[i];
					ttt.cost=T[i];
					Edge[B[i]].push_back(ttt);
				}

			}
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
        if(mark[2]==false)
            printf("-1\n");
        else
            printf("%d\n",dis[2]);
	}
	return 0;
}
