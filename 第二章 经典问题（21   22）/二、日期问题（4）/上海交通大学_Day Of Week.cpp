//2018.01.08   15.31-15:54
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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


int buf[3001][13][32];

char monthName[13][20]=
{
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char weekdayName[7][20]=
{
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
};

int main()
{
	int days;
	int year1,year2,month1,day1,day2;
	char month[20];
	int cnt=0;
	Date tmp;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=1000;
	while(tmp.Year<=3000)
	{
		buf[tmp.Year][tmp.Month][tmp.Day]=cnt++;
		tmp.NextDay();
	}///////////////////////预处理
	while(scanf("%d%s%d",&day1,month,&year1)!=EOF)
	{
		for(int i=1;i<13;i++)
			if(strcmp(month,monthName[i])==0)
				month1=i;
		days=buf[year1][month1][day1]-buf[2018][1][7];
		days=(days%7+7)%7;
		printf("%s\n",weekdayName[days]);
	}
	return 0;
}