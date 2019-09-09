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
	BigInteger operator +(const BigInteger &a)
	{
		BigInteger ret;
		ret.init();
		int i;
		int carry=0;
		int tmp;
		for(i=0;i<size||i<a.size;i++)
		{
			tmp=digit[i]+a.digit[i]+carry;
			ret.digit[ret.size++]=tmp%10000;
			carry=tmp/10000;
		}
		if(carry)
			ret.digit[ret.size++]=carry;
		return ret;
	}
	BigInteger operator *(int x)
	{
		BigInteger ret;
		ret.init();
		int tmp;
		int i;
		int carry=0;
		for(i=0;i<size;i++)
		{
			tmp=digit[i]*x+carry;
			ret.digit[ret.size++]=tmp%10000;
			carry=tmp/10000;
		}
		if(carry)
			ret.digit[ret.size++]=carry;
		return ret;
	}
	BigInteger operator /(int x)
	{
		BigInteger ret;
		ret.init();
		int i;
		int t,r=0;
		for(i=size-1;i>=0;i--)
		{
			t=(r*10000+digit[i])/x;
			r=(r*10000+digit[i])%x;
			ret.digit[i]=t;
		}
		for(i=0;i<1000;i++)
			if(ret.digit[i]!=0)
				ret.size=i;
		ret.size++;
		return ret;
	}
	int operator %(int x)
	{
		int i;
		int r=0;
		for(i=size-1;i>=0;i--)
			r=(r*10000+digit[i])%x;
		return r;
	}
	
}a,b,q;

int main()
{
	char str[10000],ans[10000];
	int L;
	int M,N;
	int i;
	int size;
	int r;
	while(scanf("%d %d",&M,&N)!=EOF)
	{
		q.set(1);////对于权的计算
		a.set(0);////用于存储中间的十进制数字
		scanf("%s",str);
		L=strlen(str);
		for(i=L-1;i>=0;i--)
		{
			if(str[i]>='0'&&str[i]<='9')
				a=a+q*(str[i]-'0');
			if(str[i]>='a'&&str[i]<='z')
				a=a+q*(str[i]-'a'+10);
			if(str[i]>='A'&&str[i]<='Z')
				a=a+q*(str[i]-'A'+10);
			q=q*M;
		}
		size=0;
		do
		{
			r=a%N;
			if(r>=10)
				ans[size++]=r-10+'a';
			else
				ans[size++]=r+'0';
			a=a/N;
		}while(!(a.digit[0]==0&&a.size==1));
		for(i=size-1;i>=0;i--)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}