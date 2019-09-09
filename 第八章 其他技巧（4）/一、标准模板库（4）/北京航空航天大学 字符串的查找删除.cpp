#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	char str[101];
	int i,t;
	string a,b,c;
	gets(str);
	a=str;
	for(i=0;i<(int)a.size();i++)
		a[i]=tolower(a[i]);
	while(gets(str))
	{
		b=str;
		c=b;
		for(i=0;i<(int)b.size();i++)
			b[i]=tolower(b[i]);
		t=b.find(a,0);
		while(t!=string::npos)
		{
			c.erase(t,a.size());
			b.erase(t,a.size());
			t=b.find(a,t);
		}
		t=c.find(' ',0);
		while(t!=string::npos)
		{
			c.erase(t,1);
			t=c.find(' ',t);
		}
		cout<<c<<endl;
	}
	return 0;
}
