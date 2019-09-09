#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[10],ans[10];
bool mark[10];
int L;

void DFS(int n)
{
	int i;
	if(n==L-1)
	{
        ans[L]='\0';
			printf("%s\n",ans);
		return;
	}
	for(i=0;i<L;i++)
		if(mark[i]==false)
		{
			mark[i]=true;
			ans[n+1]=str[i];
			DFS(n+1);
			mark[i]=false;
		}
}


int main()
{
	int i;
	while(scanf("%s",str)!=EOF)
	{
		L=strlen(str);
		sort(str,str+L);
		for(i=0;i<L;i++)
			mark[i]=false;
		for(i=0;i<L;i++)
		{
			mark[i]=true;
			ans[0]=str[i];
			DFS(0);
			mark[i]=false;
		}
        printf("\n");
	}
	return 0;
}
