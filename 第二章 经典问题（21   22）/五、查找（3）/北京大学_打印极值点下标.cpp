//2018.01.08 22:27-
#include <stdio.h>

int main()
{
	int cnt;
	int n;
	int i,j;
	int k;
	int buf[80];
	int tf[80];
	while(scanf("%d",&n)!=EOF)
	{
		for(j=0;j<n;j++)
		{
			
			cnt=0;
			scanf("%d",&k);
			for(i=0;i<k;i++)
				scanf("%d",&buf[i]);
			for(i=0;i<k;i++)
				tf[i]=0;
			if(buf[0]!=buf[1])
			{
				tf[0]=1;
				cnt++;
			}
			for(i=1;i<k-1;i++)
				if(buf[i]>buf[i-1]&&buf[i]>buf[i+1]||buf[i]<buf[i-1]&&buf[i]<buf[i+1])
				{
					tf[i]=1;
					cnt++;
				}
			if(buf[k-2]!=buf[k-1])
			{
				tf[k-1]=1;
				cnt++;
			}
			for(i=0;i<k;i++)
			{
				if(tf[i]==1&&cnt==1)
				{
					printf("%d\n",i);
					cnt--;
				}
				else if(tf[i]==1&&cnt!=1)
				{
					printf("%d ",i);
					cnt--;
				}

			}
		}
	}
	return 0;
}