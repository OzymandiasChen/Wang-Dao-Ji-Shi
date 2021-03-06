//2018.01.08 16:20-16.27
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
int cnt=0;

int main()
{
	int year1,year2,month1,month2,day1,day2;
	Date tmp;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=0;
	while(tmp.Year<=5000)
	{
		buf[tmp.Year][tmp.Month][tmp.Day]=cnt++;
		tmp.NextDay();
	}///////////////////////预处理
	while(scanf("%d%d%d",&year1,&month1,&day1)!=EOF)
	{
		printf("%d\n",buf[year1][month1][day1]-buf[year1][1][1]+1);
	}
	return 0;
}