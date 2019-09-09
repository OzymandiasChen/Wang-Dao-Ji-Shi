#include <stdio.h>
#include <stack>
using namespace std;

stack<double> in;
stack<int> op; 

char str[500];

int mat[5][5]=
{
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0
};

void getop(bool &isop,int &retn,int &i)
{
	if(i==0&&op.empty())
	{
		isop=1;
		retn=0;
		return;
	}
	if(str[i]=='\0')
	{
		isop=1;
		retn=0;
		return;
	}
	if(str[i]<='9'&&str[i]>='0')
	{
		isop=0;
		retn=0;
		while(str[i]<='9'&&str[i]>='0')
		{
			retn=retn*10+str[i]-'0';
			i++;
		}
		return;
	}
	else
	{
		isop=1;
		if(str[i]=='+')
			retn=1;
		if(str[i]=='-')
			retn=2;
		if(str[i]=='*')
			retn=3;
		if(str[i]=='/')
			retn=4;
		i++;
		return;
	}
}

int main()
{
	char ch;
	int ope;
	int i;
	double a,b,tmp;
	int retn;
	bool isop;
	while(scanf("%s",str)!=EOF)
	{
		scanf("%c",&ch);

		i=0;
		while(1)
		{
			getop(isop,retn,i);


			if(isop==0)
			{
				in.push((double)retn);

			}
			else
			{
				if(op.empty()||mat[retn][op.top()]==1)
				{

					op.push(retn);

				}
				else
				{
					while(mat[retn][op.top()]==0)
					{
						b=in.top();
						in.pop();
						a=in.top();
						in.pop();
						ope=op.top();
						op.pop();
						if(ope==1)
							tmp=a+b;
						if(ope==2)
							tmp=a-b;
						if(ope==3)
							tmp=a*b;
						if(ope==4)
							tmp=a/b;
						in.push(tmp);
	
					}
					op.push(retn);
	
				}
			}
			if(op.top()==0&&op.size()==2)
				break;
		}
		printf("%.0lf\n",in.top());
		while(!op.empty())
			op.pop();
		while(!in.empty())
			in.pop();
	}
	return 0;
}