#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s,c;
	int t;
	while(cin>>s>>c)
	{
		t=s.find(c,0);
		while(t!=string::npos)
		{
			s.erase(t,1);
			t=s.find(c,t);
		}
		cout<<s<<endl;
	}
	return 0;
}
