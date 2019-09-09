#include <stdio.h>

char maze[10][10];
int N,M,T;
bool success;
int go[][2]=
{
	1,0,
	-1,0,
	0,1,
	0,-1
};

void DFS(int x,int y,int t)//////t   D
{
	bool flag=true;
	int nx,ny;
	int i;
	if(T==t)
	{
		if(maze[x][y]=='D')
			success=true;
		return;
	}
	if(y<=0||y>M||x<=0||x>N)
		return;
	if(maze[x][y]=='X')
		return;
	if(maze[x][y]=='S')
		flag=false;
	maze[x][y]='X';
	for(i=0;i<4;i++)
	{
		nx=x+go[i][0];
		ny=y+go[i][1];
		DFS(nx,ny,t+1);
	}
	if(flag)
		maze[x][y]='.';
}

int main()
{
	int i,j;
	int dx,dy;
	while(scanf("%d%d%d",&N,&M,&T)!=EOF&&N)
	{
		success=false;
		for(i=1;i<=N;i++)
			scanf("%s",maze[i]+1);
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				if(maze[i][j]=='D')
				{
					dx=i;
					dy=j;
					break;
				}
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				if(maze[i][j]=='S')
					if(((dx+dy)%2+T%2)%2==(i+j)%2)
					{

						DFS(i,j,0);
					}

		if(success)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
