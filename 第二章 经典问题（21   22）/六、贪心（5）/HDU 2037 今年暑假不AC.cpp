/////2018.01.09 23:30-
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct se
{
	int Ti_s,Ti_e;
	bool operator <(const struct se &b)
	{
		return Ti_e<b.Ti_e;	
	};
}se;



int main()
{
	int n,i;
	int e;
	se buf[100];
	int cnt;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&buf[i].Ti_s,&buf[i].Ti_e);
		sort(buf,buf+n);
		e=0;
		cnt=0;
		for(i=0;i<n;i++)
			if(buf[i].Ti_s>=e)
			{
				cnt++;
				e=buf[i].Ti_e;
			}
		printf("%d\n",cnt);
	}
	return 0;
}