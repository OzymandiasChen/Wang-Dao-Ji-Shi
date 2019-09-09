#include <stdio.h>
#include <string.h>

struct BigInteger
{
	int digit[1000];
	int size;
	void init()
	{
		for(int i=0;i<1000;i++)
			digit[i]=0;
		size=0;
	}
	void set(int x)
	{
		init();
		do
		{
			digit[size++]=x%10000;
			x/=10000;
		}
		while(x);
	}
	void output()
	{
		int L=size;
		int i;
		for(i=L-1;i>=0;i--)
			if(i==L-1)
				printf("%d",digit[i]);
			else
				printf("%04d",digit[i]);
		printf("\n");
	}
	BigInteger operator *(int x)
	{
		BigInteger ret;
		ret.init();
		int i;
		int carry=0;
		int tmp;
		for(i=0;i<size;i++)
		{
			tmp=digit[i]*x+carry;
			carry=tmp/10000;
			ret.digit[ret.size++]=tmp%10000;
		}
		if(carry)
			ret.digit[ret.size++]=carry;
		return ret;
	}
}a;

int main()
{
	int x;
	int i;
	while(scanf("%d",&x)!=EOF)
	{
		a.set(1);
		for(i=2;i<=x;i++)
			a=a*i;
		a.output();	
	}
	return 0;
}