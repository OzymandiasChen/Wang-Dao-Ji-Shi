#include <stdio.h>
#include <queue>
using namespace std;

typedef struct N{
	int a,b,c;
	int t;
}N;
bool flag;
int s,n,m;
bool mark[101][101][101];
queue<N> Q;

int aTb(int a,int sa,int b,int sb,int c,int t,int i)
{
	N tmp;
	int cnt;
	if(a+b<=sb)
	{
		b=a+b;
		a=0;
	}
	else
	{
		
		a=a-(sb-b);
		b=sb;
	}
	if(i==1)
	{
		tmp.a=a;
		tmp.b=b;
		tmp.c=c;
		tmp.t=t+1;
	}
	if(i==2)
	{
		tmp.a=b;
		tmp.b=a;
		tmp.c=c;
		tmp.t=t+1;
	}
	if(i==3)
	{
		tmp.a=a;
		tmp.b=c;
		tmp.c=b;
		tmp.t=t+1;
	}
	if(i==4)
	{
		tmp.a=b;
		tmp.b=c;
		tmp.c=a;
		tmp.t=t+1;
	}
	if(i==5)
	{
		tmp.a=c;
		tmp.b=a;
		tmp.c=b;
		tmp.t=t+1;
	}
	if(i==6)
	{
		tmp.a=c;
		tmp.b=b;
		tmp.c=a;
		tmp.t=t+1;
	}
	if(mark[tmp.a][tmp.b][tmp.c]==false)
	{
		mark[tmp.a][tmp.b][tmp.c]=true;
		cnt=0;
		if(tmp.a==s/2)
			cnt++;
		if(tmp.b==s/2)
			cnt++;
		if(tmp.c==s/2)
			cnt++;
		if(cnt==2)
		{
			flag=true;
			return tmp.t;
		}
		Q.push(tmp);
	}
	return -1;
}

int BFS()
{
	int ret;
	int a,b,c,t;
	N tmp;
	while(!Q.empty())
	{
		tmp=Q.front();
		Q.pop();
		a=tmp.a;
		b=tmp.b;
		c=tmp.c;
		t=tmp.t;
		ret=aTb(a,s,b,n,c,t,1);
		if(flag)
			return ret;
		ret=aTb(b,n,a,s,c,t,2);
		if(flag)
			return ret;
		ret=aTb(a,s,c,m,b,t,3);
		if(flag)
			return ret;
		ret=aTb(c,m,a,s,b,t,4);
		if(flag)
			return ret;
		ret=aTb(b,n,c,m,a,t,5);
		if(flag)
			return ret;
		ret=aTb(c,m,b,n,a,t,6);
		if(flag)
			return ret;
	}
	return -1;
}

int main()
{
	N tmp;
	int i,j,k;
	int ret;
	while(scanf("%d%d%d",&s,&n,&m)!=EOF)
	{
		if(s==0&&n==0&&m==0)
			break;
		if(s%2==1)
		{
			printf("NO\n");
			continue;
		}
		flag=false;
		for(i=0;i<=s;i++)
			for(j=0;j<=n;j++)
				for(k=0;k<=m;k++)
					mark[i][j][k]=false;
		tmp.a=s;
		tmp.b=0;
		tmp.c=0;
		tmp.t=0;
		while(!Q.empty())
			Q.pop();
		Q.push(tmp);
		ret=BFS();
		if(ret==-1)
			printf("NO\n");
		else
			printf("%d\n",ret);
	}
	return 0;
}
