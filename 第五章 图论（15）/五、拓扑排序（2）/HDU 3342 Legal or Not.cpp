#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

vector<int> edge[200];
queue<int> Q;
int inDgree[200];

int main()
{
	int M,N;
	int i;
	int cnt;
	int a,b;
	int now;
	while(scanf("%d %d",&N,&M)!=EOF&&N!=0)
	{
		for(i=0;i<N;i++)
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
		for(i=0;i<N;i++)
			if(inDgree[i]==0)
                Q.push(i);
  		cnt=0;
		while(!Q.empty())
		{
			now=Q.front();
			Q.pop();
			cnt++;
			for(i=0;i<edge[now].size();i++)
			{
				inDgree[edge[now][i]]--;
				if(inDgree[edge[now][i]]==0)
					Q.push(edge[now][i]);
			}
        }
		if(cnt==N)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

