#include <stdio.h>
#include <string.h>

int main()
{
	int a,b;
	char s[100],ans[100];
	long tmp;
	int x;
	int q;
	int i,size,id;
	while(scanf("%d %s %d",&a,s,&b)!=EOF)
	{
		q=1;////权重
		tmp=0;
		for(i=strlen(s)-1;i>=0;i--)
		{
			if(s[i]>='0'&&s[i]<='9')
				tmp+=(s[i]-'0')*q;
			if(s[i]>='a'&&s[i]<='f')
				tmp+=(s[i]-'a'+10)*q;
			if(s[i]>='A'&&s[i]<='F')
				tmp+=(s[i]-'A'+10)*q;
			q*=a;
		}
		size=0;
		do
		{
			x=tmp%b;
			ans[size++]=(x<10) ? x+'0':x-10+'A';
			tmp/=b;
		}while(tmp);
		for(i=size-1;i>=0;i--)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}