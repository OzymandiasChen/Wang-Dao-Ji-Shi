#include <stdio.h>

int sod(int t)
{
	int ans=0;
	while(t)
	{
		ans+=t%10;
		t/=10;
	}
	return ans;
}

int main()
{
	int n;
	int sr;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		sr=n;
		while(1)
		{
			sr=sod(sr);
			if(sr>0&&sr<10)
				break;
		}
		printf("%d\n",sr);
	}
	return 0;
}