#include <stdio.h>

int rev(int num)
{
	int ans=0;
	while(num)
	{
		ans=ans*10+num%10;
		num/=10;
	}
	return ans;
}

int main()
{
	int a,b,ans;
	int n;
	int ar,br,ansr;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		ar=rev(a);
		br=rev(b);
		ans=ar+br;
		ansr=rev(a+b);
		if(ans==ansr)
			printf("%d\n",a+b);
		else 
			printf("NO\n");
	}
	return 0;
}