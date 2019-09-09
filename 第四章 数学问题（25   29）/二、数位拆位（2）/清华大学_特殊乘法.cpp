#include <stdio.h>

int main()
{
	char a[30],b[30];
	char ch;
	int i,j;
	int ans;
	while(scanf("%s %s",a,b)!=EOF)
	{
		ans=0;
		scanf("%c",&ch);
		for(i=0;a[i]!='\0';i++)
			for(j=0;b[j]!='\0';j++)
				ans+=(a[i]-'0')*(b[j]-'0');
		printf("%d\n",ans);
	}
	return 0;
}