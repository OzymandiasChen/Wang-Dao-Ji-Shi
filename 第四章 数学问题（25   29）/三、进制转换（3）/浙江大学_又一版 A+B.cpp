#include <stdio.h>

int main()
{
	int m;
	long A,B,tmp;
	int i,id;
	int s[100];
	while(scanf("%d",&m)!=EOF&&m)
	{
		scanf("%ld %ld",&A,&B);
		tmp=A+B;
		i=0;
		do
		{
			s[i++]=tmp%m;
			tmp/=m;
		}
		while(tmp);
		for(id=i-1;id>=0;id--)
			printf("%d",s[id]);
		printf("\n");
	}
	return 0;
}