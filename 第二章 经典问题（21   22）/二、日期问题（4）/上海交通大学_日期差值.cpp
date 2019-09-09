//2018.01.08   14.17-14.54
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


int buf[5001][13][32];

int main()
{
	int year1,year2,month1,month2,day1,day2;
	int cnt=0;
	Date tmp;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=0;
	while(tmp.Year<=5000)
	{
		buf[tmp.Year][tmp.Month][tmp.Day]=cnt++;
		tmp.NextDay();
	}///////////////////////预处理
	while(scanf("%4d%2d%2d",&year1,&month1,&day1)!=EOF)
	{
		scanf("%4d%2d%2d",&year2,&month2,&day2);
		printf("%d\n",abs(buf[year2][month2][day2]-buf[year1][month1][day1])+1);
	}
	return 0;
}