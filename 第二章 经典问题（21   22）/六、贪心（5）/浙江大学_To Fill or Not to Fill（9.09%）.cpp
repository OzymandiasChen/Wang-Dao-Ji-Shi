//2018 01.10 1:08-

//①没有加油站，------- 快到终点了，则加适量油到终点；或者 Impossible，则A站加满油到哪算哪；
//②有更便宜的加油站 ------- 则找到第一家比A便宜的加油站B，加尽可能少的油（也可能油够直接开过去）
// 到B站；
//③只有价格更高的加油站，------则当下A站加满油，寻找相对最便宜的加油站B 开过去。

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct sta
{
	double Pi;
	double Di;
	bool operator < (const struct sta &b)
	{
		return Di<b.Di;
	}
}sta;

int main()
{
	double Cmax,D,Davg,maxdiss,tank;
	int N;
	sta buf[500];
	int i,j,tmpsta;
	double pri,X,tmppri;
	while(scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N)!=EOF)
	{
		for(i=0;i<N;i++)
			scanf("%lf%lf",&buf[i].Pi,&buf[i].Di);
		sort(buf,buf+N);
		i=0;
		pri=0;
		tank=0;
		X=0;
		maxdiss=Davg*Cmax;
		if(buf[0].Di!=0)
		{
			printf("The maximum travel distance = 0.00\n");
			continue;
		}
		while(X<D&&i<N)
		{
			
			////就找下一个相对便宜的站
			j=i;
			tmppri=buf[i].Pi;
			tmpsta=i;
			while((buf[j].Di-buf[i].Di)<=maxdiss)////可以到达的目标内
			{
				if(buf[j].Pi<tmppri)
					{
						tmppri=buf[j].Pi;
						tmpsta=j;
					}
				j++;
			}
		    ////找完了
			if(tmpsta==i)////如果当前站是可到达的最便宜的
			{
				if((X+tank*Davg)>=D)///如果可以直接开到终点的话
				{
					printf("%.2lf\n",pri);
					break;
				}
				pri+=Cmax*buf[i].Pi;
				if((buf[i+1].Di-buf[i].Di)<=maxdiss)///如果可以开到下一站，开
				{
					tank-=(buf[i+1].Di-buf[i].Di)/Davg;
					i++;
					X=buf[i].Di;
				}
				else//////如果开不到
				{
					printf("The maximum travel distance = %.2lf\n",X+maxdiss);
					break;
				}
			}
			else//////前方有一可到达的，比较便宜的，那就去
			{
				if(tank>(buf[tmpsta].Di-buf[i].Di)/Davg)////如果现在的油可到
				{
					tank-=(buf[tmpsta].Di-buf[i].Di)/Davg;
					i=tmpsta;
					X=buf[tmpsta].Di;
				}
				else/////如果现在的油不可到,加油，加到可到的地步,开去
				{
					pri+=(buf[tmpsta].Di-buf[i].Di)/Davg*buf[i].Pi;///加油
					tank=0;
					i=tmpsta;
					X=buf[tmpsta].Di;
				}
			}
		}
	}
	return 0;
}