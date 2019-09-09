#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int &a,int &b)
{
	return a>b;
}

int main()
{
	int L,n;
	int buf[600];
	int i;
	int ans;
	while(scanf("%d%d",&L,&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&buf[i]);
		sort(buf,buf+n,cmp);
		ans=0;
		i=0;
		while(L>0&&i<n)
		{
			L-=buf[i];
			i++;
			ans++;
		}
		if(L>0)
			printf("impossible\n");
		else
			printf("%d\n",ans);			
	}
	return 0;
}