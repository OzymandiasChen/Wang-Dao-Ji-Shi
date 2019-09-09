#include <stdio.h>
#include <queue>
using namespace std;

bool mark[50][50][50];
int maze[50][50][50];
typedef struct N
{
	int x,y,z;
	int t;
}N;
queue<N> Q;
int go[][3]=
{
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
int BFS(int a,int b,int c)
{
	N now,tmp;
	int i;
	int nx,ny,nz;
	while(!Q.empty())
	{
		now=Q.front();
		Q.pop();
		for(i=0;i<6;i++)
		{
			nx=now.x+go[i][0];
			ny=now.y+go[i][1];
			nz=now.z+go[i][2];
			if(nx<0||ny<0||nz<0||nx>=a||ny>=b||nz>=c)
				continue;
			if(maze[nx][ny][nz]==1)
				continue;
			if(mark[nx][ny][nz]==true)
				continue;
			tmp.x=nx;
			tmp.y=ny;
			tmp.z=nz;
			tmp.t=now.t+1;
			Q.push(tmp);
			mark[nx][ny][nz]=true;
			if(nx==a-1&&ny==b-1&&nz==c-1)
				return tmp.t;
		}
	}
	return -1;
}

int main()
{
	int T;
	int a,b,c,t;
	int i,j,k;
	N tmp;
	int rec;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				for(k=0;k<c;k++)
				{
					scanf("%d",&maze[i][j][k]);
					mark[i][j][k]=false;
				}
		while(!Q.empty())
			Q.pop();
		mark[0][0][0]=true;
		tmp.x=0;
		tmp.y=0;
		tmp.z=0;
		tmp.t=0;
		Q.push(tmp);
		rec=BFS(a,b,c);
		if(rec<=t)
			printf("%d\n",rec);
		else
			printf("-1\n");
	}
	return 0;
}
