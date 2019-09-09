#include <stdio.h>
#define M 9973

void mul(int a[11][11],int b[11][11],int c[11][11],int n)
{
	int ans[11][11];
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			ans[i][j]=0;
			for(k=0;k<n;k++)
			{
				ans[i][j]+=a[i][k]*b[k][j];
				ans[i][j]%=M;
			}
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			c[i][j]=ans[i][j];
}

int main()
{
	int A[11][11];
	int ans[11][11];
	int T;
	int n,k;
	int i,j;
	int t;
    scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&A[i][j]);
				A[i][j]%=M;
			}
		///////现在A是1次的
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				ans[i][j]=(i==j?1:0);
		while(k)
		{
			if(k%2==1)
			{
				mul(ans,A,ans,n);
			}
			k/=2;
			mul(A,A,A,n);
		}
		t=0;
		for(i=0;i<n;i++)
		{
			t+=ans[i][i];
			t%=M;
		}
		printf("%d\n",t);
	}
	return 0;
}