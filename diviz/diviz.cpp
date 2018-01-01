#include<fstream>
#include<cstring>
#define mod 3013
using namespace std;
ifstream cin("diviz.in");
ofstream cout("diviz.out");
int a,b,k,i,y[201][101],x[11][201][101],n[201][101],t,j,kk,p,sol;
char v[201];
int main()
{
    cin>>k>>a>>b;
    cin>>v;
    for(i=1;i<=(int)strlen(v);i++)
    {
        t=v[i-1]-'0';
        for(j=b;j>=0;j--)
            for(kk=0;kk<k;kk++)
            y[j][kk]=x[t][j][kk];
        for(j=b;j>=0;j--)
            for(kk=0;kk<k;kk++)
            {
                p=(10*kk+t)%k;
                x[t][j][p]+=n[j-1][kk];
                x[t][j][p]%=mod;
            }
        for(j=b;j>=0;j--)
            for(kk=0;kk<k;kk++)
            {
                x[t][j][kk]=(x[t][j][kk]+mod-y[j][kk])%mod;
                n[j][kk]=(n[j][kk]+x[t][j][kk]+mod-y[j][kk])%mod;
            }
        if(t)
        {
            if(x[t][1][t%k]==0)
                n[1][t%k]++;
            x[t][1][t%k]=1;
        }
    }
    for(i=a;i<=b;++i)
    {
        sol+=n[i][0];
        sol%=mod;
    }
    cout<<sol<<'\n';
    return 0;
}

