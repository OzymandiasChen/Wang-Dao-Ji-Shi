#include <stdio.h>
#include <map>
#include <string>
using namespace std;

map<string,int> M;
int in[2001];

int main()
{
	int n;
	int i,j;
	int idx,cnt;
	int ans;
	char ch;
	char a[50];
	string str;
	while(scanf("%d",&n)!=EOF&&n)
	{
		cnt=0;
		for(i=0;i<2001;i++)
			in[i]=0;
		M.clear();
		////init!!!!
		for(i=1;i<=2*n;i++)
		{
			scanf("%s",a);
			str=a;
			if(M.find(str)==M.end())
			{
				idx=cnt;
				M[a]=cnt++;
			}
			else
				idx=M[a];
			if(i%2==0)
				in[idx]++;
		}
		ans=0;
		for(i=0;i<cnt;i++)
			if(in[i]==0)
				ans++;
		printf(ans==1?"Yes\n":"No\n");

	}
	return 0;
}
