#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

char name[2051][100];
int size;
int stn(char n[])
{
	int i;
	for(i=1;i<=size;i++)
		if(strcmp(name[i],n)==0)
			return i;
	strcpy(name[i],n);
	size++;
	return i;
}

vector<int> edge[2051];
int inDgree[2051];

int main()
{
	char x[100],y[100];
	int n;
	int i;
	int cnt;
	int a,b;
	int now;
	char ch;
	bool flag;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		////初始化
		scanf("%c",&ch);
		for(i=1;i<=2050;i++)
			name[i][0]='\0';
		size=0;
		for(i=1;i<=2050;i++)
		{
			inDgree[i]=0;
			edge[i].clear();
		}
		for(i=0;i<n;i++)
		{
			scanf("%s%s",x,y);
			scanf("%c",&ch);
			a=stn(x);
			b=stn(y);
			edge[a].push_back(b);
			inDgree[b]++;
		}
		cnt=0;
		for(i=1;i<=size;i++)
			if(inDgree[i]==0)
                cnt++;
        if(cnt==1)
        	printf("Yes\n");
        else
        	printf("No\n");
	}
	return 0;
}
