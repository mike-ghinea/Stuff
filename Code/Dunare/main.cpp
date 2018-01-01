#include <fstream>
#define dim 5001
#include<algorithm>
using namespace std;
ifstream fin("dunarea.in");
ofstream fout ("dunarea.out");

struct prd
{
    int x,y;
} v[dim],a[dim];
int cmp(prd o, prd p)
{
    if(o.x==p.x)
        return o.y > p.y;
    return o.x < p.x;
}

int x,y,n,nr,x1,x2,i,Max,val;
int main()
{
    fin>>x>>y>>n;

    for(i=1; i<=n; i++)
    {
        fin>>x1;
        v[i].x=x1;
        fin>>x2;
        v[i].y=x2;
    }

    sort(v+1,v+n+1,cmp);
    a[1].x = v[1].x;
    a[1].y = v[1].y;
    int sz=1;
    for(i=2;i<=n;i++)
    {
        if(v[i].x > a[sz].x)
        {
            a[++sz].x = v[i].x;
            a[sz].y = v[i].y;
        }
    }
    nr=1;
    val = a[1].y;
    for(i=1;i<=sz&&val<y;i++)
    {
        Max = 0;
        while(a[i].x <= val)
        {
            Max= max(Max, a[i].y);
            i++;
        }
        val=Max;
        i--;
        nr++;
    }
    fout<<nr;
    return 0;
}
