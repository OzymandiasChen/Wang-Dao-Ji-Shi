///2018.01.09 21:32-
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	double J;
	double F;
}JF;

bool cmp(const JF &a,const JF &b)
{
	return a.F/a.J<b.F/b.J;
}

int main()
{
	int m;
	int N;
	int i;
	double cnt,M;
	JF buf[1000];
	while(scanf("%d%d",&m,&N)!=EOF&&m!=-1&&N!=-1)
	{
		for(i=0;i<N;i++)
			scanf("%lf%lf",&buf[i].J,&buf[i].F);
		sort(buf,buf+N,cmp);
		cnt=0;
		i=0;
		M=(double)m;
		while(M>0&&i<N)
		{
			if(M>=buf[i].F)
			{
				cnt+=buf[i].J;
				M=M-buf[i].F;
			}
			else
			{
				cnt+=buf[i].J*M/buf[i].F;
				M=0;
			}
			i++;
		}
		printf("%.3lf\n",cnt);
	}
	return 0;
}