#include <queue>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int a,b,tmp,ans,i;
	priority_queue<int, vector<int>, greater<int> > Q;
	//////由大到小排列，top为最小
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int i=n;
		while(i--)
		{
			scanf("%d",&tmp);
			Q.push(tmp);
		}
		ans=0;
		i=n-1;
		while(i--)
		{
			a=Q.top();
			Q.pop();
			b=Q.top();
			Q.pop();
			tmp=a+b;
			ans+=tmp;
			Q.push(tmp);
		}
		printf("%d\n",ans);
		Q.pop();
	}
	return 0;
}