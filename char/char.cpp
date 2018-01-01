#include<fstream>
using namespace std;
ifstream cin("char.in");
ofstream cout("char.out");
int n,i,h,p[100],sw,k,j,aux,Max,nr,t,i1,j1,m,s[10003],d[10003];
char x[100001],y[100];
int putere(char c)
{
    int i;
    for (i=1;i<=h;i++)
        if (y[i]==c)
            return p[i];
    return 0;
}
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    cin>>x[i];
    cin>>h;
    for(i=1;i<=h;i++)
        cin>>p[i];
    k=0;
    for (i=1;i<=n;i++)
    {
        sw=1;
        for (j=1;j<=k;j++)
            if (y[j]==x[i])
            {
                sw=0;
                break;
            }
        if (sw)
        {
            k++;
            y[k]=x[i];
        }
    }
    for (i=1;i<k;i++)
        for (j=i+1;j<=k;j++)
            if (y[i]>y[j])
            {
                aux=y[i];
                y[i]=y[j];
                y[j]=aux;
            }
    Max=0;
    for (i=1;i<=h;i++)
        if (p[i]>Max)
            Max=p[i];
    nr=0;
    for (i=1;i<=n;i++)
        if (Max==putere(x[i])) nr++;
    for (i=1;i<=n;i++)
    {
        t=putere(x[i]);
        i1=i-t;
        j1=i+t;
        if (i1<0) i1=0;
        if (j1>n) j1=n;
        s[i]=i1;
        d[i]=j1;
// cout<<i1<<" "<<j1<<'\n';
    }
    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++)
            if (d[i]>d[j])
            {
                aux=s[i];
                s[i]=s[j];
                s[j]=aux;
                aux=d[i];
                d[i]=d[j];
                d[j]=aux;
            }
    i=1;
    m=1;//cout<<s[1]<<" "<<d[1]<<'\n';
    for (j=2;j<=n;j++)
        if (s[j]>d[i])
        {
            m++;
            i=j;
//   cout<<s[i]<<" "<<d[i]<<'\n';
        }
    cout<<nr<<'\n'<<m;

}
