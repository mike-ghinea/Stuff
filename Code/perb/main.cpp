#include <fstream>
#include <string.h>

#define inf 10000
using namespace std;
ifstream fin("perb.in");
ofstream fout("perb.out");
int i,j,n,m,k,l,sum,v[603],D[603][603],x,y,d,ap[603][4],c,nrmax,valc,nr,a[603][603];
char ch;
int val(char x)
{
    if(x=='A')
        return 0;
    if(x=='C')
        return 1;
    if(x=='G')
        return 2;
    return 3;
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>ch;
        v[i]=val(ch);
    }
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            D[i][j]=j-i;


    for(d=1;d*2<=n;++d)
    {
        for(i=1;i+2*d-1<=n;++i)
        {
            j=i+d-1;
            a[i][j]=0;
            for(k=i;k<j+d;++k)
            {
                memset(ap[k-i],0,sizeof(ap[k-i]));
                ap[k-i][v[k]]=1;
            }
            nr=1;
            for(j=i+2*d-1;j<=n;j+=d)
            {
                ++nr;
                a[i][j]=0;
                for(k=0;k<d;++k)
                {
                    ++ap[k][v[j-d+1+k]];
                    a[i][j]+=nr-max(max(ap[k][0],ap[k][1]),max(ap[k][2],ap[k][3]));
                }
                if(a[i][j]< D[i][j])
                    D[i][j]=a[i][j];
               // D[i][j]=min(D[i][j],a[i][j]);
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        fin>>x>>y;
        fout<<D[x][y]<<'\n';
    }
    return 0;
}
