#include <stdio.h>
#include <string.h>

char str1[100],str2[100];
int sti (char str[])
{
	int ans=0;
	int q=1;
	int i=strlen(str)-1;
	for(;i>=0&&str[i]!='-';i--)
	{
		if(str[i]==',')
			continue;
		ans+=(str[i]-'0')*q;
		q*=10;
	}
	if(i==0)
		ans*=-1;
	return ans;
}

int main()
{
	int a,b;
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		a=sti(str1);
		b=sti(str2);
		printf("%d\n",a+b);
	}
	return 0;
}
