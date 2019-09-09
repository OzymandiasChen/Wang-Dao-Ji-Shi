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
	int nx,ny;
	int i;
	for(i=0;i<4;i++)
	{
		nx=x+go[i][0];
		ny=y+go[i][1];
		if(ny<=0||ny>M||nx<=0||nx>N)
			continue;
		if(maze[nx][ny]=='X')
			continue;
		if(maze[nx]n[y]=='D')
			if(T==t+1)
			{
				success=true;
				return;
			}
			else
				continue;
		maze[nx][ny]='X';
		DFS(nx,ny,t+1);
		maze[nx][ny]='.';
		if(success)
			return;
	}
}

int main()
{
	int i,j;
	int dx,dy;
	while(scanf("%d%d%d",&N,&M,&T)!=EOF&&N&&M&&T)
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
						maze[i][j]='X';
						DFS(i,j,0);
					}

		if(success)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
