#include <stdio.h>
#include <string.h>
/////digit内的内容类似于小端法
/////低的存在前边
//////类似于PC里的工作过程

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
	void set(char str[])
	{
		init();
		int L=strlen(str);
		int q=1;
		int tmp=0;
		int cnt=0;
		for(int i=L-1;i>=0;i--)
		{
			tmp=tmp+(str[i]-'0')*q;
			q*=10;
			cnt++;
			if(cnt==4||i==0)
			{
				digit[size++]=tmp;
				q=1;
				cnt=0;
				tmp=0;
			}
		}
	}
	void output()
	{
		for(int i=size-1;i>=0;i--)
			if(i==size-1)
				printf("%d",digit[i]);
			else
				printf("%04d",digit[i]);
		printf("\n");
	}
	BigInteger operator + (const BigInteger &a)
	{
		struct BigInteger ret;
		ret.init();
		int carry=0;
		int tmp;
		int i;
		for(i=0;i<a.size||i<size;i++)
		{
			tmp=a.digit[i]+digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ret.digit[ret.size++]=tmp;
		}
		if(carry!=0)
			ret.digit[ret.size++]=carry;
		return ret;
	}
}a,b,c;

int main()
{
	char str1[1001],str2[1001];
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		a.set(str1);
		b.set(str2);
		c=a+b;
		c.output();
	}
	return 0;
}