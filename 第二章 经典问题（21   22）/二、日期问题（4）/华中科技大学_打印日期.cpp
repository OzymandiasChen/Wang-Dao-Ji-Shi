///2018.01.08 16:28-16:50
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define runnian(x) x%100!=0&&x%4==0||x%400==0?1:0

int DayOfMonth[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};

typedef struct
{
	int Day;
	int Month;
	int Year;
	void NextDay()
	{
		Day++;
		if(Day>DayOfMonth[Month][runnian(Year)])
		{
			Day=1;
			Month++;
			if(Month>12)
			{
				Month=1;
				Year++;
			}
		}		
	}
}Date;


int main()
{
	Date tmp;
	int count;//////
	while(scanf("%d%d",&tmp.Year,&count)!=EOF)
	{
		tmp.Day=1;
		tmp.Month=1;
		for(int i=1;i<count;i++)
			tmp.NextDay();
		printf("%04d-%02d-%02d\n",tmp.Year,tmp.Month,tmp.Day);
	}
	return 0;
}
