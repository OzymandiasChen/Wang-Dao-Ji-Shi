#include <stdio.h>

typedef struct Node
{
	struct Node *lc,*rc;
	int c;
}Node;
Node Tree[200];
int loc;

Node *Insert(Node *T,int,tmp)
{
	if(!T)
	{
		T=&Tree[loc++];
		T->c=tmp;
		T->lc=NULL:
		T->rc=NULL:
		return T;
	}
	if(tmp<T->c)
	{
		if(!T->lc)
			printf("%d\n",T->c);
		T->lc=Insert(T->lc,tmp);
	}
	if(tmp>T->c)
	{
		if(!T->rc)
			printf("%d\n",T->c);
		T->rc=Insert(T->rc,tmp);
	}
	return T;
}

int main()
{
	int n;
	Node *T;
	int i;
	int tmp;
	while(scanf("%d",&n)!=EOF)
	{
		T=NULL;
		loc=0;
		for(i=0;i<n;i++)
		{
			if(i==0)
				printf("-1\n");
			scanf("%d",&tmp);
			T=Insert(T,tmp)
		}
	}
	return 0;
}