#include <stdio.h>

int main()
{
	int N;
	int T;
	while(scanf("%d",&N)!=EOF)
	{
		if(N/10)
			if(N*N%100==N)
				printf("Yes!\n");
			else
				printf("No!\n");
		else
			if(N*N%10==N)
				printf("Yes!\n");
			else
				printf("No!\n");
	}

	return 0;
}