//2018 01.08 21:15
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct student{
	char xh[10];
	char xm[80];
	char xb[50];
	int age;
    bool operator<(const struct student &b)
    {
        return strcmp(xh,b.xh)<0;
    }
}student;



int main()
{
	student buf[1000];
	int M,N;
	int i;
	int h,l,mid;
	char xh[10];
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
			scanf("%s%s%s%d",buf[i].xh,buf[i].xm,buf[i].xb,&buf[i].age);
			
		sort(buf,buf+N);
		scanf("%d",&M);
		for(i=0;i<M;i++)
		{
			scanf("%s",xh);
			h=N-1;
			l=0;
			while(h>=l)
			{
				mid=(h+l)/2;
				if(strcmp(xh,buf[mid].xh)>0)
					l=mid+1;
				else if(strcmp(xh,buf[mid].xh)<0)
					h=mid-1;
				else 
				{
					printf("%s %s %s %d\n",buf[mid].xh,buf[mid].xm,buf[mid].xb,buf[mid].age);
					break;
				}
			}
			if(h<l)
				printf("No Answer!\n");
		}	
	}
	return 0;
}