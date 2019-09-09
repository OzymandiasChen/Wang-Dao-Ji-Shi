///////2018.01.12 17:03-
#include <stdio.h>
#include <string.h>

int loc;
typedef struct Node 
{
	struct Node *lc;
	struct Node *rc;
	char c;
}Node;
Node Tree[100];
char ans1[20];
char ans2[20];
char *ans;
int *id;
int id1,id2;

Node *Insert(Node *T,char c)
{
	if(!T)
	{
		T=&Tree[loc++];
		T->c=c;
		T->lc=NULL;
		T->rc=NULL;
		return T;
	}
	if(c<T->c)
		T->lc=Insert(T->lc,c);
	if(c>T->c)
		T->rc=Insert(T->rc,c);
	return T;

}

void xxbl(Node *T)
{
	ans[(*id)++]=T->c;
	if(T->lc)
		xxbl(T->lc);
	if(T->rc)
		xxbl(T->rc);
}

void zxbl(Node *T)
{
	if(T->lc)
		zxbl(T->lc);
	ans[(*id)++]=T->c;
	if(T->rc)
		zxbl(T->rc);
}

int main()
{
	char ch;
	int n;
	int i;

	char str1[20];
	char str2[20];
	Node *T1,*T2;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%c",&ch);
		loc=0;
		if(n==0)
			break;

		T1=NULL;
		scanf("%s",str1);
		scanf("%c",&ch);
		for(i=0;str1[i]!='\0';i++)
			T1=Insert(T1,str1[i]);
		ans=ans1;
		id1=0;
		id=&id1;
		xxbl(T1);
		zxbl(T1);
		ans1[id1]='\0';
		while(n--)
		{
			T2=NULL;
			scanf("%s",str2);
			scanf("%c",&ch);
			for(i=0;str2[i]!='\0';i++)
				T2=Insert(T2,str2[i]);
			ans=ans2;
			id2=0;
			id=&id2;
			xxbl(T2);
			zxbl(T2);
			ans2[id2]='\0';
			printf(strcmp(ans1,ans2)==0 ? "YES\n":"NO\n");
		}
	}
	return 0;
}