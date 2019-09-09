//2018.01.08 21:50-21:02
#include <stdio.h>

int main()
{
	int buf[200];
	int n,x,ans;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&buf[i]);
		ans=-1;
		scanf("%d",&x);
		for(i=0;i<n;i++)
			if(x==buf[i])
				ans=i;
		printf("%d\n",ans);
	}
	return 0;
}