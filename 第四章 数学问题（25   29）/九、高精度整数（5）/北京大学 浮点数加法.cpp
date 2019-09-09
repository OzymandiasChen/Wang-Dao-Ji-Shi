#include <stdio.h>
#include <string.h>
char str1[200],str2[200];
struct fl
{
	int p[200],q[200];
	int sizep,sizeq;
	void init()
	{
		int i;
		for(i=0;i<200;i++)
		{
			p[i]=0;
			q[i]=0;
			sizep=0;
			sizeq=0;
		}
	}
	void set(char str[])
	{
		init();
		int i;
		int loc;
		int L=strlen(str);
		for(loc=0;str[loc]!='.';loc++);
		///q正着放
		for(i=loc+1;str[i]!='\0';i++)
			q[sizeq++]=str[i]-'0';
		///p倒着放
		for(i=loc-1;i>=0;i--)
			p[sizep++]=str[i]-'0';
	}
	void output()
	{
		int i;
		for(i=sizep-1;i>=0;i--)
			printf("%d",p[i]);
		printf(".");
		for(i=0;i<sizeq;i++)
			printf("%d",q[i]);
		printf("\n");
	}
	fl operator + (const fl &a)
	{
		fl ret;
		ret.init();
		int i;
		int carry=0;
		int t;
		ret.sizeq=(sizeq>a.sizeq?sizeq:a.sizeq);
		for(i=ret.sizeq-1;i>=0;i--)
		{
			t=q[i]+a.q[i]+carry;
			ret.q[i]=t%10;
			carry=t/10;
		}
		for(i=0;i<sizep||i<a.sizep;i++)
		{
			t=p[i]+a.p[i]+carry;
			ret.p[ret.sizep++]=t%10;
			carry=t/10;
		}
		if(carry)
			ret.p[ret.sizep++]=carry;
		return ret;
	}
}a,b,c;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s%s",str1,str2);
			a.set(str1);
			b.set(str2);
			c=a+b;
			c.output();
		}
	}
	return 0;
}