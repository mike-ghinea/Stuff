#include<fstream>
using namespace std;
ifstream cin("cmmdc.in");
ofstream cout("cmmdc.out");
int a,b;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
 	cin>>a>>b;
 	if(gcd(a,b)!=1)
        cout<<gcd(a,b);
    else
        cout<<0;
	return 0;
}
