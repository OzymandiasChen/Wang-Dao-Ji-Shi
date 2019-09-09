#include <stdio.h>

int ans[22];
bool hash[22];
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};

bool judge(int x)
{
	for(int i=0;i<13;i++)
		if(prime[i]==x)
			return true;
	return false;
}

void check()
{
	if(judge(ans[n]+ans[1])==false)
		return;
	for(int i=1;i<=n;i++)
		if(i==n)
			printf("%d\n",ans[i]);
		else
			printf("%d ",ans[i]);
}

void DFS(int num)////num已经有多少个数字存入其中
{
	int i;
	if(num!=1)
		if(judge(ans[num-1]+ans[num])==false)
			return;
	if(num==n)
	{
		check();
		return;
	}
	////以上均为退出条件
	for(i=2;i<=n;i++)
		if(hash[i]==false)
		{
			hash[i]=true;
			ans[num+1]=i;
			DFS(num+1);
			hash[i]=false;////恢复现场
		}
}
int main()
{
	int cnt=0;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		cnt++;
		for(i=0;i<22;i++)
			hash[i]=false;
		ans[1]=1;
		hash[1]=true;
		printf("Case %d:\n",cnt);
		DFS(1);
		printf("\n");
	}
	return 0;
}
