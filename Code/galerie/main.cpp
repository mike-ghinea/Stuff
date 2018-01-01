#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("galerie.in");
ofstream fout("galerie.out");
int nr,poz,val,start,finish,n,m,t,i,cup;
long long arb[400001],b[250001],nr1;
struct car
{
    int x,y,z,tip;
}v[350001];
int cmp(car o, car p)
{
    if(o.x==p.x)
    {
       if(o.y==p.y)
            return o.tip<p.tip;
        return o.y>p.y;
    }
    return o.x<p.x;
}
void update(int nod, int st, int dr)
{
    if(st==dr)
    {
        arb[nod] += val;
        return;
    }
    int mij = (st+dr)/2;
    if(poz <= mij)
        update(2*nod,st,mij);
    else
        update(2*nod+1,mij+1,dr);
    arb[nod] = arb[2*nod] + arb[2*nod +1];
}
void query(int nod, int st, int dr)
{
    if(start<=st && finish >=dr)
    {
        nr1+=arb[nod];
        return;
    }
    int mij = (st+dr)/2;
    if(start <= mij)
        query(2*nod, st, mij);
    if(mij< finish)
        query(2*nod+1,mij+1,dr);

}
int main()
{
    fin>>n>>m>>t;
    for(i=1;i<=m;i++)
    {
        nr++;
        fin>>v[nr].x>>v[nr].y>>v[nr].z;
        if(v[nr].x > v[nr].y)
        {
            cup = v[nr].x;
            v[nr].x = v[nr].y;
            v[nr].y = cup;
        }
        v[nr].tip = 0;
    }
    for(i=1;i<=t;i++)
    {
        nr++;
        fin>>v[nr].x>>v[nr].y>>v[nr].z;
        if(v[nr].x > v[nr].y)
        {
            cup = v[nr].x;
            v[nr].x = v[nr].y;
            v[nr].y = cup;
        }
        v[nr].tip = i;
    }
    sort(v+1,v+nr+1,cmp);
    for(i=1;i<=nr;i++)
    {
        if(v[i].tip==0)
        {
            val = v[i].z;
            poz = v[i].y;
            update(1,1,n);
            continue;
        }

        start = v[i].y;
        finish = n;
        if(v[i].y-v[i].x-v[i].z>0)
        {
            nr1=0;
            query(1,1,n);
            b[v[i].tip]=nr1*(v[i].y-v[i].x-v[i].z);
        }

    }
    for(i=1;i<=t;i++)
        fout<<b[i]<<'\n';
    return 0;
}
