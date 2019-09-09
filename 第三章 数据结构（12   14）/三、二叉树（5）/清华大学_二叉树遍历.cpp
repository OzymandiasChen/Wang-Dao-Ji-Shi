#include <stdio.h>
#include <string.h>

typedef struct Node
{
	struct Node *lc;
	struct Node *rc;
	char c;
}Node;

int i;
int loc;
int k;
Node Tree[200];
char str[200];
char ans[200];

Node *create()
{
	char c;
	c=str[i++];
	if(c=='#')
		return NULL;
	Node *T=&Tree[loc++];
	T->c=c;
	T->lc=create();
	T->rc=create();
	return T;
}

void Inorder(Node *T)
{
	if(T->lc)
		Inorder(T->lc);
	ans[k++]=T->c;
	if(T->rc)
		Inorder(T->rc);
}

int main()
{
	Node *T;
	int L;
	int j;
	while(scanf("%s",str)!=EOF)
	{
		i=0;
		loc=0;
		k=0;
		T=create();
		Inorder(T);
		ans[k]='\0';
		L=strlen(ans);
		for(j=0;j<L;j++)
			printf("%c ",ans[j]);
		printf("\n");
	}
	return 0;
}