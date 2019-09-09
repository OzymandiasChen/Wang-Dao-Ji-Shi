#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

vector<int> edge[501];
priority_queue<int,vector<int>,greater<int> > Q;////建立一格小顶堆
int inDgree[501];

int main()
{
	int M,N;
	int i;
	int cnt;
	int a,b;
	int now;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(i=1;i<=N;i++)
		{
			inDgree[i]=0;
			edge[i].clear();
		}
		while(!Q.empty())
			Q.pop();
		for(i=0;i<M;i++)
		{
			scanf("%d %d",&a,&b);
			edge[a].push_back(b);
			inDgree[b]++;
		}
		for(i=1;i<=N;i++)
			if(inDgree[i]==0)
                Q.push(i);
  		cnt=0;
		while(!Q.empty())
		{
			now=Q.top();
			Q.pop();
			cnt++;
			if(cnt==N)
			{
				printf("%d\n",now);
				break;
			}
			else
				printf("%d ",now);
			for(i=0;i<edge[now].size();i++)
			{
				inDgree[edge[now][i]]--;
				if(inDgree[edge[now][i]]==0)
					Q.push(edge[now][i]);
			}
        }
	}
	return 0;
}

