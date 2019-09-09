#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char buf[100][1000];

static bool cmp(char a[],char b[])
{
	int a1=strlen(a);
	int b1=strlen(b);
	int i;
	bool ret=false;
	if(a1!=b1)
		return (a1<b1?true:false);
	for(i=0;i<a1;i++)
		if(a[i]<b[i])
			ret=true;
	return ret;
}

int main()
{
	int n;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%s",buf[i]);
		sort(buf,buf+n,cmp);
		for(i=0;i<n;i++)
			printf("%s\n",buf[i]);
	}
	return 0;
}