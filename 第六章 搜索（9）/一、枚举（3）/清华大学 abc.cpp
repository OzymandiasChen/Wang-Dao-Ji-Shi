#include <stdio.h>

int main()
{
	int a,b,c;
	int tmp;
	for(a=0;a<10;a++)
		for(b=0;b<10;b++)
			for(c=0;c<10;c++)
			{
				tmp=(a+b)*100+(b+c)*10+c+c;
				if(tmp==532)
					printf("%d %d %d\n",a,b,c);
			}
	return 0;
}