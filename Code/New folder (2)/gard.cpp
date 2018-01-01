#include<fstream>
using namespace std;
ifstream cin("gardul.in");
ofstream cout("gardul.out");
int n,x,y,a,b,c,d,m;
int main()
{
 	cin>>n>>x>>y;
 	while(1)
    {
        m+=x;
        if(m%y==0)
            break;
    }
 	d=n/m;
 	b=n/x-d;
 	c=n/y-d;
 	a=n-b-c-d;
    cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d;
	return 0;
}
