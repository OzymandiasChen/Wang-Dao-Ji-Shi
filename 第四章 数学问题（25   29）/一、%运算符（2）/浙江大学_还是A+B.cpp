#include <stdio.h>
#include <math.h>

int main()
{
	int A,B,K;
	int C;
	int i;
	bool flag;
	while(scanf("%d %d %d",&A,&B,&K)!=EOF)
	{
		if(A==0&&B==0)
			break;
		flag=1;
		for(i=0;i<K;i++)
		{
			C=(int)pow(10,i);
			if((A/C)%10!=(B/C)%10)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("-1\n");
		else
			printf("%d\n",A+B);
	}
	return 0;
}