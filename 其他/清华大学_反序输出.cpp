#include <stdio.h>

int main()
{
    char a[10];
    while(scanf("%s",a)!=EOF)
    {
        printf("%c%c%c%c\n",a[3],a[2],a[1],a[0]);
    }
	
	return 0;
}