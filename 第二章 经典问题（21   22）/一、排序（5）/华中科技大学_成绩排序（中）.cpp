//////1、使用运算符重载
//////2、使用结构体 定义cmp

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct 
{
	char name[100];
	int age;
	int score;
}student;

/////cmp 如果返回的是true的话，
bool operator < (const student &c,const student &b) 
{
	int a=strcmp(c.name,b.name);
	if(c.score!=b.score) return c.score<b.score;
	else if(a)
		return a<0;
	else
		return c.age<b.age;
}


int main()
{
	int i;
	student s[1000];
	int n;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>s[i].name>>s[i].age>>s[i].score;
		sort(s,s+n);
		for(int i=0;i<n;i++)
			cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].score<<endl;
	}
	return 0;
}