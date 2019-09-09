#include <stdio.h>
#include <stack>
using namespace std;

/////是因为对scanf的理解错了，真是tm的该
//////fflush(stdin);
int main()
{
	int n;
	char ins,ch;
	int a;
	stack<int> S;
	while(scanf("%d\n",&n)!=EOF)
	{
        if(n==0)
            break;
		while(n--)
		{
			scanf("%c%c",&ins,&ch);
			if(ins=='P')
			{
				scanf("%d\n",&a);
				S.push(a);
			}
			if(ins=='O')
				if(!S.empty())
					S.pop();
			if(ins=='A')
				if(!S.empty())
					printf("%d\n",S.top());
				else
					printf("E\n");
		}
		printf("\n");
		while(!S.empty())
			S.pop();
	}
	return 0;
}