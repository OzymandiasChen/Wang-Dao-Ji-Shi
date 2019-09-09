///////使用sort排序，cmp的使用
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i;
	int n;////每一行的整数个数
	int  buf[100];
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>buf[i];
		sort(buf,buf+n);
		for(i=0;i<n;i++)
			cout<<buf[i]<<" ";
		cout<<endl;
	}
	return 0;
}