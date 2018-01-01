#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");
int n,i,j,ok,h;
struct str
{
    int x, y;
}v[8192];
struct compa
{
    int x, y;
}comp[8192];
int cmp(str o, str p)
{
    if(o.x>p.x)
        return 0;
    else
        if(o.x==p.x)
            if(o.y<p.y)
                return 0;
    return 1;
}
int main()
{
fin>>n;
if(n==1)
    fout<<1;
else
{
for(i=1;i<=n;i++)
    fin>>v[i].x>>v[i].y;
sort(v+1,v+n+1,cmp);
for(i=1;i<=n;i++)
{
    ok=0;
    for(j=1;j<=h;j++)
    {
        if(v[i].x<=comp[j].y&&h!=0)
        {
            if(v[i].y<=comp[j].y)
            {
                comp[j].x=v[i].x;
                comp[j].y=v[i].y;
            }
            else
                comp[j].x=v[i].x;
            ok=1;
            break;
        }
    }
    if(ok==0)
    {
        comp[++h].x=v[i].x;
        comp[h].y=v[i].y;
    }
}
fout<<h;
}
    return 0;
}
