#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("text3.in");
ofstream cout("text3.out");
char a,m[21000][25],s,lit;
int nr=1,u=0,i,l[21000],p[21000],lsol,psol,lmax[256],pmax[256];
int main()
{
    while(cin.get(a))
    {
        if(a==' ')
        {
            nr++;
            u=0;
            continue;
        }
        if(a==10&&m[nr][0])
        {
            nr++;
            u=0;
            continue;
        }
        if(a!=10)
        {
            m[nr][u]=a;
            u++;
        }
    }
    cout<<nr-1<<'\n';
    for(i=1;i<=nr;i++)
    {
        lit=m[i][0];
        l[i]=lmax[(int)lit]+1;
        p[i]=pmax[(int)lit];
        lit=m[i][strlen(m[i])-1];
        if(l[i]>lmax[(int)lit])
        {
            lmax[(int)lit]=l[i];
            pmax[(int)lit]=i;
        }
    }
    lsol=0;
    for(lit='a';lit<='z';lit++)
        if(lmax[(int)lit]>=lsol)
        {
            lsol=lmax[(int)lit];
            psol=pmax[(int)lit];
        }
    cout<<nr-lsol-1<<'\n';
    i=psol;
    while(p[i]!=0)
    {
        l[p[i]]=i;
        i=p[i];
    }
    while(i!=psol)
    {
        cout<<m[i]<<'\n';
        i=l[i];
    }
    cout<<m[psol];
    return 0;
}
