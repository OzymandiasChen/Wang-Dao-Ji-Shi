#include <stdio.h>
#include <string.h>

typedef struct Node{
	struct Node *lc;
	struct Node *rc;
	int num;
}Node;

Node Tree[110];
int loc;

Node *Insert(Node  *T,int num)
{
	if(!T)
	{
		T=&(Tree[loc++]);
		T->num=num;
		T->lc=NULL;
		T->rc=NULL;

		return T;
	}
	if(T->num>num)
	{

		T->lc=Insert(T->lc,num);
	}
	if(T->num<num)
	{

		T->rc=Insert(T->rc,num);
	}
	return T;
}

void xxbl(Node  *T)
{
	printf("%d ",T->num);
	if(T->lc)
		xxbl(T->lc);
	if(T->rc)
		xxbl(T->rc);
}

void zxbl(Node  *T)
{
	if(T->lc)
		zxbl(T->lc);
	printf("%d ",T->num);
	if(T->rc)
		zxbl(T->rc);
}

void hxbl(Node  *T)
{
	if(T->lc)
		hxbl(T->lc);
	if(T->rc)
		hxbl(T->rc);
	printf("%d ",T->num);
}

int main()
{
	int n;
	int num;
	int i;
	Node *T;
	while(scanf("%d",&n)!=EOF)
	{
		T=NULL;
		loc=0;
		for(i=0;i<n;i++)
		{

			scanf("%d",&num);
			T=Insert(T,num);
		}
		xxbl(T);
		printf("\n");
		zxbl(T);
		printf("\n");
		hxbl(T);
		printf("\n");
	}
	return 0;
}