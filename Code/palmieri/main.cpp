#include <fstream>
#include <algorithm>

#define dim 250002
using namespace std;
ifstream fin("palmieri.in");
ofstream fout("palmieri.out");
int n,a,i,sol,ymax,xi,poz;
struct strct
{
    int x,y;
}v[dim];
bool cmp(strct o, strct p)
{
    if(o.x==p.x)
        return o.y<p.y;
    return o.x<p.x;
}
int main()
{
    fin>>n>>a;
    for(i=1;i<=n;i++)
    {
        fin>>v[i].x>>v[i].y;
    }
    sort(v+1,v+n+1,cmp);
    poz=1;
    for(i=2;i<=n;i++)
    {
        while(v[poz].x==v[i].x)
        {
            i++;
        }
        v[poz].y=v[i-1].y;
        v[++poz].x=v[i].x;
        v[poz].y=v[i].y;
    }
    xi=v[1].x;
    ymax=v[i].y;
    sol=1;
    for(i=2;i<=poz;i++)
    {
        ymax=max(ymax,v[i].y);
        if((v[i].x-xi)*ymax>a)
        {
            sol++;
            ymax=v[i].y;
            xi=v[i].x;
        }
    }
    fout<<sol;
    return 0;
}
