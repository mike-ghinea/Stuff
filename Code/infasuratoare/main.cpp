#include <fstream>
#include <algorithm>
#include <iomanip>

#define Ndim 120010
#define x first
#define y second
using namespace std;
ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");
typedef pair<double,double> strct;
int N,vf;
strct V[Ndim],stck[Ndim];
void read()
{
    fin>>N;
    for(int i=1;i<=N;i++)
        fin>>V[i].x>>V[i].y;
}
inline double plan(const strct &a,const strct &b,const strct &c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
inline int cmp(const strct &a,const strct &b)
{
    return plan(V[1],a,b)<0;
}
void sort_points()
{
    int pos = 1;
    for(int i=2;i<=N;i++)
        if(V[i]<V[pos])
            pos=i;
    swap(V[1],V[pos]);
    sort(V+2,V+N+1,cmp);
}
void convex_hull()
{
    sort_points();
    stck[1]=V[1];
    stck[2]=V[2];
    vf=2;
    for(int i=3;i<=N;i++)
    {
        while(vf>=2 && plan(stck[vf-1],stck[vf],V[i])>0)
            vf--;
        stck[++vf]=V[i];
    }
}
void write()
{
    fout<<fixed;
    fout<<vf<<'\n';
    while(vf)
    {
        fout<<setprecision(9)<<stck[vf].x<<' '<<stck[vf].y<<'\n';
        vf--;
    }
}
int main()
{
    read();
    convex_hull();
    write();
    return 0;
}
