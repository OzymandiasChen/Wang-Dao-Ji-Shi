#include <stdio.h>
#define M 200907

int main()
{
	int n;
	int k;
	long long a,b,c;
	scanf("%d",&n);
	long long tmp,q;
	int i;
	while(n--)
	{
		scanf("%lld %lld %lld %d",&a,&b,&c,&k);
		if((b-a)==(c-b))
		{
				tmp=(a%M+((b-a)%M)*((k-1)%M)%M)%M;
		}
		else
		{
			tmp=a%M;
			k--;
            q=(b/a)%M;
            while(k!=0)
            {
                if(k%2==1)
                {
                    tmp*=q;
                    tmp%=M;
                }
                k/=2;
                q*=q;
                q%=M;
            }
		}
		printf("%lld\n",tmp);
	}
	return 0;
}
