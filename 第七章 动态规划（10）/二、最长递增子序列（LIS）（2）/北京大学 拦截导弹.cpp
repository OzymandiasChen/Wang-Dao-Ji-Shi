#include <stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int list[26];
int F[26];

int main()
{
	int k;
	int i,j;
	int mmax;
	while(scanf("%d",&k)!=EOF)
	{
		for(i=1;i<=k;i++)
			scanf("%d",&list[i]);
		F[1]=1;
		for(i=2;i<=k;i++)
		{
			mmax=1;
			for(j=1;j<i;j++)
				if(list[i]<=list[j])
					mmax=max(mmax,F[j]+1);
			F[i]=mmax;
		}
		mmax=0;
		for(i=1;i<=k;i++)
			mmax=max(mmax,F[i]);
		printf("%d\n",mmax);
	}
	return 0;
}
