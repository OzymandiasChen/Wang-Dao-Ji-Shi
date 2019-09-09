///////////经典的sorthecmp，只是麻烦了一点而已
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct 
{
	char id[7];
	char name[100];
	int score;
}student;

int identify=0;

bool cmp1(const student &a,const student &b)
{
	int c=strcmp(a.id,b.id);
	return c<0;
}

bool cmp2(const student &a,const student &b)
{
	int c=strcmp(a.name,b.name);
	int d=strcmp(a.id,b.id);
	if(c)
		return c<0;
	else
		return d<0;
}
bool cmp3(const student &a,const student &b)
{
	int d=strcmp(a.id,b.id);
	if(a.score!=b.score)
		return a.score<b.score;
	else
		return d<0;
}

int main()
{
	student buf[100000];
	int i;
	int N,C;
	while(cin>>N)
	{
		cin>>C;
		identify++;
        if(N==0)
            return 0;
		for(i=0;i<N;i++)
			cin>>buf[i].id>>buf[i].name>>buf[i].score;
        if(N==1)
        {
        	 cout<<"Case "<<identify<<":"<<endl;
             cout<<buf[0].id<<" "<<buf[0].name<<" "<<buf[0].score<<endl;
        }
        else
        {
           if(C==1)
				sort(buf,buf+N,cmp1);
			else if(C==2)
				sort(buf,buf+N,cmp2);
			else
				sort(buf,buf+N,cmp3);
			cout<<"Case "<<identify<<":"<<endl;
			for(i=0;i<N;i++)
				cout<<buf[i].id<<" "<<buf[i].name<<" "<<buf[i].score<<endl; 
        }
	}
	return 0;
}