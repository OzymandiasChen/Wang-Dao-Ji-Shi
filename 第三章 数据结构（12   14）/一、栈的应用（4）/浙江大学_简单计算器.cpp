/////
#include <stack>
#include <stdio.h>

using namespace std;

char str[220];
int mat[5][5]=/////优先级大于///优先级矩阵
{
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack<double> in;
stack<int> op;

void getop(bool &reto1,int &retn1,int &i1)
{
	if(i1==0&&op.empty())
	{
		reto1=true;
		retn1=0;
		return;
	}
	if(str[i1]=='\0')
	{
		reto1=1;
		retn1=0;
		return;
	}
	if(str[i1]==' ')//////因为没有连续的空格，所以一定每次会取到有效的
		i1++;

	if(str[i1]>='0'&&str[i1]<='9')
	{
		reto1=0;
		retn1=0;
		for(;str[i1]!=' '&&str[i1]!='\0';i1++)
			retn1=retn1*10+str[i1]-'0';
		return;
	}
	else
	{
		reto1=1;
		if(str[i1]=='+')
			retn1=1;
		if(str[i1]=='-')
			retn1=2;
		if(str[i1]=='*')
			retn1=3;
		if(str[i1]=='/')
			retn1=4;
		i1+=2;

		return;
	}
}

int main()
{
	bool reto;
	int retn;
	int i;
	double a,b;
	int ope;
	char ch;
	while(gets(str))
	{
		while(!op.empty())
			op.pop();
		while(!in.empty())
			in.pop();
		if(str[0]=='0'&&str[1]=='\0')
			break;
		i=0;
		while(1)
		{
			getop(reto,retn,i);
			if(reto==0)
			{
				in.push(retn);
			}
			else
			{
				if(op.empty())
				{
					op.push(retn);

				}
				else if(mat[retn][op.top()]==1)
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
							in.push(a+b);
						if(ope==2)
							in.push(a-b);
						if(ope==3)
							in.push(a*b);
						if(ope==4)
							in.push(a/b);
					}
					op.push(retn);
				}
				if(op.top()==0&&op.size()==2)
					break;//////可以表达式里只有一个数
			}
		}
		printf("%.2lf\n",in.top());

	}
	return 0;
}
