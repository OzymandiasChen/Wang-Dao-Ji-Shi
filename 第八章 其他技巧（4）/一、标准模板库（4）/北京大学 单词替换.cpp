#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	char a[200],b[200],c[200];
	string str,x,y;
	int t;
	int tmp;
	while(gets(a))
	{
		str=a;
		str=' '+str+' ';
		gets(b);
		gets(c);
		x=b;
		x=' '+x+' ';
		y=c;
		y=' '+y+' ';
		t=str.find(x,0);
		while(t!=string::npos)
		{
			str.erase(t,x.size());
			str.insert(t,y);
			t=str.find(x,t);
		}
		str.erase(0,1);
		tmp=str.size();
		str.erase(tmp-1,1);
		printf("%s\n",str.c_str());
	}
	return 0;
}
