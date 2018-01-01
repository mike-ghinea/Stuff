#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>

#define NDIM 1010
using namespace std;
ifstream fin("desen.in");
ofstream fout("desen.out");
int n,i,nrp,x[NDIM],y[NDIM],ind,dsj[NDIM],last;
struct strct{int x,y,val;}d[100004];
bool viz[100004];
double sol;
bool cmp(const strct &a, const strct &b)
{
    return a.val<b.val;
}
int dist(int a,int b)
{
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
int root(int k)
{
    while(dsj[k])
        k=dsj[k];
    return k;
}
void join(int a, int b)
{
    dsj[root(a)]=root(b);
}
int main()
{
    fin>>n;
    fin>>x[1]>>y[1];
    fout<<0.000<<'\n';
    for(nrp=2;nrp<=n;nrp++)
    {
        fin>>x[nrp]>>y[nrp];
        ind=nrp-2;
        for(i=1;i<=nrp-1;i++)
        {
            d[++ind].val=dist(nrp,i);
            d[ind].x=nrp;
            d[ind].y=i;
        }
        for(i=1;i<=nrp;i++)
            dsj[i]=0;
        sort(d+1,d+ind+1,cmp);
        sol=0;
        memset(viz,0,sizeof(viz));
        for(i=1;i<=ind;i++)
        {
            if(root(d[i].x)!=root(d[i].y))
            {
                last=i;
                viz[i]=1;
                sol+=sqrt(d[i].val);
                join(d[i].x,d[i].y);
            }
        }
        int dev=0;
        for(i=1;i<=last;i++)
        {
            if(viz[i]==1)
            {
                d[i-dev].val=d[i].val;
                d[i-dev].x=d[i].x;
                d[i-dev].y=d[i].y;
            }
            else
                dev++;
        }
        fout<<fixed<<setprecision(4)<<sol<<'\n';
    }
    return 0;
}
