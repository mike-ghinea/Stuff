#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin ("int.in");
ofstream fout ("int.out");

struct strct
{
 int x,y;
}v[50001];
bool cmp (strct o,strct p)
{
    if(o.y==p.y)
        return o.x<p.x;
    return o.y<p.y;
}
int n,k,i,nr;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>v[i].x>>v[i].y;
    }
    sort(v+1,v+n+1,cmp);
    k=v[1].y;
    nr=1;
    for(i=2;i<=n;i++)
    {
        if(v[i].x>=k)
        {
            k=v[i].y;
            nr++;
        }
    }
    fout<<nr;
    return 0;
}
