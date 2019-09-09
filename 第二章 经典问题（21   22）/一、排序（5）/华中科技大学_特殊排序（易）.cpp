#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i;
	int buf[1000];
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>buf[i];
		sort(buf,buf+n);
		cout<<buf[n-1]<<endl;
        if(n==1)
            cout<<"-1"<<endl;
        else{
            for(i=0;i<(n-2);i++)
				cout<<buf[i]<<" ";
			cout<<buf[n-2]<<endl; 
        }

	}
	return 0;
}