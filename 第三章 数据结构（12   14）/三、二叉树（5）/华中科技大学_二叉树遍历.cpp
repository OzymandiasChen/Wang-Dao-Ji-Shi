#include <stdio.h>
#include <string.h>

typedef struct Node
{
	struct Node *lc;
	struct Node *rc;
	char c;
}Node;

Node Tree[50];

int loc;

Node *create()
{
	Tree[loc].lc=NULL;
	Tree[loc].rc=NULL;
	return &Tree[loc++];
}

char str1[30],str2[30];

void PostOrder(Node *T)
{
	if(T->lc)
		PostOrder(T->lc);
	if(T->rc)
		PostOrder(T->rc);
	printf("%c",T->c);	
}

Node *bulid(int s1,int e1,int s2,int e2)
{
	int i;
	Node *ret=create();
	ret->c=str1[s1];
	for(i=s2;str2[i]!=str1[s1];i++);
	if(i!=s2)
		ret->lc=bulid(s1+1,s1+i-s2,s2,i-1);
	if(i!=e2)
		ret->rc=bulid(s1+i-s2+1,e1,i+1,e2);
	return ret;
}

int main()
{
	int L1,L2;
	Node *T;
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		loc=0;
		L1=strlen(str1);
		L2=strlen(str2);
		T=bulid(0,L1-1,0,L2-1);
		PostOrder(T);
		printf("\n");
	}
	return 0;
}
