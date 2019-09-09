#include <iosream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	char buf[201];
	int n;
	while(cin>>buf)
	{
		n=strlen(buf);
		sort(buf,buf+n);
		cout<<buf<<endl;
	}
	return 0;
}