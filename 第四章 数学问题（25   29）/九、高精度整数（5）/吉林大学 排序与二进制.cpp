#include <stdio.h>

int main()
{
	int m,n;
	int i;
	int ans;
	int t;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		ans=0;
		for(i=n-m+1;i<=n;i++)
		{
			t=i;
			while(t%2==0)
			{
				ans++;
				t/=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}