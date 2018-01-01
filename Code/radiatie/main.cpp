#include <fstream>
#include <algorithm>
#include <vector>

#define NDIM 15005
#define MDIM 30005
using namespace std;
ifstream fin("radiatie.in");
ofstream fout("radiatie.out");

int n,m,k,i,a,b,c[NDIM],t[NDIM],lv[NDIM],x,y,sol;
vector <int> G[NDIM];
struct strct{int x,y,c;}v[MDIM];
bool cmp(strct o, strct p)
{
    return o.c<p.c;
}
int root(int k)
{
    while(t[k])
        k=t[k];
    return k;
}
void dfs(int nod)
{
    for(size_t i=0;i<G[nod].size();++i)
    {
        lv[G[nod][i]]=lv[nod]+1;
        dfs(G[nod][i]);
    }
}
int main()
{
    fin>>n>>m>>k;
    for(i=1;i<=m;++i)
        fin>>v[i].x>>v[i].y>>v[i].c;
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=m;++i)
    {
        a=root(v[i].x);
        b=root(v[i].y);
        if(a!=b)
        {
           t[a]=b;
           G[b].push_back(a);
           c[a]=v[i].c;
        }
    }
    for(i=1;t[i];++i);
    dfs(i);
    while(k--)
    {
        fin>>x>>y;
        sol=0;
        if(lv[x]<lv[y])
            swap(x,y);
        while(lv[x]>lv[y])
        {
            sol=max(sol,c[x]);
            x=t[x];
        }
        while(x!=y)
        {
            sol=max(sol,max(c[x],c[y]));
            x=t[x];
            y=t[y];
        }
        fout<<sol<<'\n';
    }
//    for(i=1;i<=n;i++)
//    {
//        for(int j=0;j<G[i].size();j++)
//            fout<<G[i][j]<<' ';
//        fout<<'\n';
//    }
    return 0;
}
