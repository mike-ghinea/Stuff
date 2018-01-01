#include<fstream>
#include<cstring>
#define mod 30103
using namespace std;
ifstream cin("diviz.in");
ofstream cout("diviz.out");
int a,b,k,i,y[202][102],c,x[11][202][102],n[202][102],t,j,kk,p,sol;
char v[202];
int main()
{
    cin>>k>>a>>b;
    cin>>(v+1);
    c=strlen(v+1);
    for(i=1;i<=c;i++)
    {
        t=v[i]-'0';
        for(j=b;j>0;j--)
            for(kk=0;kk<k;kk++)
            y[j][kk]=x[t][j][kk];
        for(j=b;j>0;j--)
            for(kk=0;kk<k;kk++)
            {
                p=(10*kk+t)%k;
                x[t][j][p]+=n[j-1][kk];
                x[t][j][p]%=mod;
            }
        for(j=b;j>0;j--)
            for(kk=0;kk<k;kk++)
            {
                x[t][j][kk]=(x[t][j][kk]+mod-y[j][kk])%mod;
                n[j][kk]=(n[j][kk]+x[t][j][kk]+mod-y[j][kk])%mod;
            }
        if(t)
        {
            if(x[t][1][t%k]==0)
                ++n[1][t%k];
            x[t][1][t%k]=1;
        }
    }
    for(i=a;i<=b;i++)
    {
        sol+=n[i][0];
        sol%=mod;
    }
    cout<<sol<<'\n';
    return 0;
}
