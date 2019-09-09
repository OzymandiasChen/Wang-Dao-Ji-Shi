#include <stdio.h>
#include <math.h>

bool judge(int x)
{
	bool flag=true;
	if(x<=1)
		return false;
	int t=(int)sqrt(x);
	for(int i=2;i<=t;i++)
		if(!(x%i))
		{
			flag=false; 
			return flag;
		}
	return flag;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
		printf(judge(n)?"yes\n":"no\n");
	return 0;
}