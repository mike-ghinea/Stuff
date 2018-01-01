#include<fstream>
#include<math.h>
using namespace std;
ifstream cin("pesti.in");
ofstream cout("pesti.out");
unsigned long n,x,z,a,b,c,u,zi,p;
long double r;
int main()
{
 	cin>>n>>x;
 	r=logl(n)/logl(2);
 	if (r==floorl(r))
        z=r-1;
    else
        z=r;
    a=1;b=n;u=0;
    while(b-a>1)
    {
        p=x;
        if((x-a)%2==0)
        {
           b=(a+b)/2;
           x=a+(x-a)/2;
        }
        else
        {
            c=(a+b)/2;
            x=c+(x-a+1)/2;
            a=c+1;
        }
        u++;
        if(x!=p)
            zi=u;
    }
    cout<<z<<" "<<x<<" "<<zi;
	return 0;
}
