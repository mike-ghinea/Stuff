#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("zero.in");
ofstream fout("zero.out");
short int l,baz,p,q,lim,pas,i,j,poz;
int b[21][21],sum,sump,a[21][21],s,sumq;
int main()
{
    fin>>l>>baz>>p>>q;
    baz--;
    b[0][0]=baz;
    lim=l;
    for(pas=2;pas<=l;pas++)
    {
        memcpy(a,b,sizeof(a));
        b[0][0]=a[0][0]*baz;
        for(i=0;i<=lim;i++)
        {
            s=0;
            for(j=0;j<=lim;j++)
            {
                if(j<=i)
                    s+=a[i][j];
                if(j>0)
                    b[i][j]=a[i][j-1];
            }
            for(j=0;j<i;j++)
                s+=a[j][i];
            if(i>0)
                b[i][0]=s*baz;

        }
        /*for(i=0;i<=lim;i++)
        {
            for(j=0;j<=lim;j++)
                fout<<b[i][j]<<' ';
            fout<<'\n';
        }
        fout<<'\n';*/

    }
    for(i=0;i<=lim;i++)
    {
        for(j=0;j<=lim;j++)
        {
            if(i<=p&&j<=p)
                sump+=b[i][j];
            if(i<q&&j<q)
                sumq+=b[i][j];
        }
    }
    sum=baz;
    for(i=2;i<=l;i++)
    {
        sum*=(baz+1);
    }
    fout<<sump<<'\n'<<sum-sumq;
    return 0;
}
