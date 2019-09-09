#include <stdio.h>

bool mark[101][101];////对没有遍历过的pocket遍历
char maze[101][102];
int cnt;
int m,n;
int go[][2]=
{
	1,0,
	-1,0,
	0,1,
	0,-1,
	-1,-1,
	-1,1,
	1,1,
	1,-1,
};

void DFS(int x,int y)
{
	int i;
	int nx,ny;
	for(i=0;i<8;i++)
	{
		nx=x+go[i][0];
		ny=y+go[i][1];
		if(nx>0&&nx<=m&&ny>0&&ny<=n)
			if(mark[nx][ny]==false&&maze[nx][ny]=='@')
			{
				mark[nx][ny]=true;
				DFS(nx,ny);
			}
	}
}


int main()
{
	int i,j;
	while(scanf("%d %d",&m,&n)!=EOF&&m)
	{
		for(i=1;i<=m;i++)
			scanf("%s",maze[i]+1);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				mark[i][j]=false;
		cnt=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(maze[i][j]=='@'&&mark[i][j]==false)
				{
					mark[i][j]=true;
					cnt++;
					DFS(i,j);
				}
		printf("%d\n",cnt);
	}
	return 0;
}
