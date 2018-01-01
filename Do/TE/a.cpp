#include <iostream>
#include <math.h>
using namespace std;

long long sol=1,nr,M,MOD=1000000007,VIZ[200004],cnt,N=1,nrdiv=1;
long long lgput(long long n,long long p)
{
    long long r=1;
    while(p)
    {
        if(p%2==1)
        {
            r*=n;
            r%=MOD;
        }
        n*=(n%MOD);
        n%=MOD;
        p/=2;
    }
    return r;
}
int main()
{
    cin>>M;
    for(int i=1;i<=M;i++)
    {
        cin>>nr;
        VIZ[nr]++;
        N = N*nr % MOD;
    }
    for(int i=1;i<=200000;i++)
    {
        if(VIZ[i])
            nrdiv *= (VIZ[i]+1);
    }
    if(nrdiv%2==1)
        cout<<sqrt(lgput(N,nrdiv));
    else
    cout<<lgput(N,(nrdiv)/2);
    return 0;
}
