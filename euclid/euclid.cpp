#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int i,n,a,b;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
 	cin>>n;
 	for(i=1;i<=n;i++)
 	{
 	    cin>>a>>b;
        cout<<gcd(a,b)<<"\n";
 	}
	return 0;
}
