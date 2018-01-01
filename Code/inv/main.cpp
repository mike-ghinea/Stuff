#include <fstream>
#include <algorithm>

#define dim 100001
#define mod 9917

using namespace std;
ifstream fin("inv.in");
ofstream fout("inv.out");
int start, pos, finish, arb[4*dim], nr, sol, n, i;
void query(int nod, int st, int dr)
{
    if(start<=st && finish >=dr)
    {
        nr=(nr+arb[nod])%mod;
        return;
    }
    int mij = (st+dr)/2;
    if(start <= mij)
        query(2*nod,st,mij);
    if(mij < finish)
        query(2*nod+1,mij+1,dr);
}
void update(int nod, int st, int dr)
{
    if(st==dr)
    {
        arb[nod]++;
        return;
    }
    int mij = (st+dr)/2;
    if(pos <= mij)
        update(2*nod, st, mij);
    else
        update(2*nod+1, mij+1, dr);
    arb[nod]++;
}
struct strct{
    long long x; int y;
}v[dim];
int cmp(strct o, strct p)
{
    if(o.x == p.x)
        return o.y < p.y;
    return o.x < p.x;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>v[i].x;
        v[i].y = i;
    }
    sort(v+1,v+n+1,cmp);

    for(i=1;i<=n;i++)
    {
        pos=v[i].y;
        start = pos+1;
        finish = n;
        nr=0;
        query(1,1,n);
        sol=(nr%mod + sol% mod)%mod;
        update(1,1,n);
    }
    fout<<sol%mod;
    return 0;
}
