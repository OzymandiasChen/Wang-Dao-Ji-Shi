#include <stdio.h>

long long gcd(long long a,long long b)
{
	return (b==0)?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}

int main()
{
	long long buf[10000];
	int m,n;
	int i;

	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%lld",&buf[i]);
		for(i=0;i<m-1;i++)
			buf[i+1]=lcm(buf[i],buf[i+1]);
		printf("%lld\n",buf[m-1]);
	}	
	return 0;
}