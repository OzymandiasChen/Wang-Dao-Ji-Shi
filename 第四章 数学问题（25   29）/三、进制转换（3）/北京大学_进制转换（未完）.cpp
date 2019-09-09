#include <stdio.h>
#include <string.h>

int main()
{
	int M,N;
	char s[100],ans[100];
	char ch;
	int q;
	int i,size;
	long num;
	int x,tmp;
	while(scanf("%d %d",&M,&N)!=EOF)
	{
		scanf("%s",s);
		scanf("%c",&ch);
		q=1;
		num=0;
		for(i=strlen(s)-1;i>=0;i--)
		{
			if(s[i]>='0'&&s[i]<='9')
				x=s[i]-'0';
			if(s[i]>='a'&&s[i]<='z')
				x=s[i]-'a'+10;
			if(s[i]>='A'&&s[i]<='Z')
				x=s[i]-'A'+10;
			num+=x*q;
			q*=M;
		}
		size=0;
		do
		{
			tmp=num%N;
			if(tmp>=0&&tmp<=9)
				ans[size++]=tmp+'0';
			else
				ans[size++]=tmp-10+'a';
			num/=N;
		}while(num);
		for(i=size-1;i>=0;i--)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}