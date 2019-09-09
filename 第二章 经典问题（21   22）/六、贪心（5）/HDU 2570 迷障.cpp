#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int C,n,V,W,cnt;
	int i;
	double Pi[1000];
	double P,tmp;
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d%d%d",&n,&V,&W);
		for(i=0;i<n;i++)
			scanf("%lf",&Pi[i]);
		sort(Pi,Pi+n);
		P=0;
		cnt=0;
		tmp=0;
		i=0;
		while(P<=W&&i<n)
		{
			tmp=P;
			tmp=(tmp*cnt+Pi[i])/(cnt+1);
			if(tmp<=W)
			{
				P=tmp;
				cnt++;
			}
			i++;
		}
		if(cnt==0)
			printf("0 0.00\n");
		else
			printf("%d %.2lf\n",cnt*V,P/100);
	}
	return 0;
}