#include<fstream>
using namespace std;
ifstream cin("minusk.in");
ofstream cout("minusk.out");
int sum[1000002],m[1000002],p[1000002],n,k,i;
int main()
{
    cin>>n>>k;
    p[1]=1;
    m[1]=1;
    sum[1]=1;
    for(i=2;i<=n;i++)
    {
        p[i]=p[i-1]+m[i-1];
        p[i]%=2011;
        sum[i]=sum[i-1]+p[i];
        sum[i]%=2011;
        if(i-k<0)
            m[i]=p[i];
        else
            m[i]=sum[i-1]-sum[i-k];
        m[i]%=2011;
        if(p[i]<0)
            p[i]+=2011;
        if(m[i]<0)
            m[i]+=2011;
        if(sum[i]<0)
            sum[i]+=2011;
    }
    if(p[n]+m[n]>=0)
        cout<<(p[n]+m[n])%2011;
    else
        cout<<(p[n]+m[n]+2011)%2011;
    return 0;
}
