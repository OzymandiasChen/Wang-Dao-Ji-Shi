//2018.01.08 17:12-17:20
#include <iostream>
using namespace std;

int main()
{
	int N;
	int tmp;
	int grade;
	while(cin>>N&&N!=0)
	{
		int score[101]={0};
		for(int i=0;i<N;i++)
		{
			cin>>tmp;
			score[tmp]++;
		}
		cin>>grade;
		cout<<score[grade]<<endl;
	}
	return 0;
}