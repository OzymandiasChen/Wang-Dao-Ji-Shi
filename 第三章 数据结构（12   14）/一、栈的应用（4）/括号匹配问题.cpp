#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	char str[110];
	char ans[110];
	stack<int> S;
	int i;
	while(gets(str))
	{
		for(i=0;str[i]!='\0';i++)
			if(str[i]=='(')
			{
				ans[i]=' ';
				S.push(i);
			}
			else if(str[i]==')')
				if(!S.empty())
				{
					S.pop();
					ans[i]=' ';
				}
				else
					ans[i]='?';
			else
				ans[i]=' ';
		ans[i]='\0';
		while(!S.empty())
		{
			ans[S.top()]='$';
			S.pop();
		}	

		puts(ans);
	}
	return 0;
}