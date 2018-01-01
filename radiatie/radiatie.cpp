#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct E{int x,y,v;} e[30001];
int n,m,k,t[15001],lv[15001],c[15001];
vector<int> g[15001];
bool cmp(E a,E b) {return a.v<b.v;}
int root(int x)
{
    while(t[x])
        x=t[x];
    return x;
}
void dfs(int nod)
{
    for(size_t i=0;i<g[nod].size();++i)
    {
        lv[g[nod][i]]=lv[nod]+1;
        dfs(g[nod][i]);
    }
}
ifstream fin("radiatie.in");
ofstream fout("radiatie.out");
int main()
{
    int i,x,y,mx;
    fin>>n>>m>>k;
    for(i=0;i<m;++i)
        fin>>e[i].x>>e[i].y>>e[i].v;
    sort(e,e+m,cmp);
    for(i=0;i<m;++i)
    {
        x=root(e[i].x);
        y=root(e[i].y);
        if(x!=y)
        {
            t[x]=y;
            g[y].push_back(x);
            c[x]=e[i].v;
        }
    }
    for(i=1;t[i];++i);
    dfs(i);
    while(k--)
    {
        fin>>x>>y;
        mx=0;
        if(lv[x]<lv[y])
            swap(x,y);
        while(lv[x]>lv[y])
        {
            mx=max(mx,c[x]);
            x=t[x];
        }
        while(x!=y)
        {
            mx=max(mx,max(c[x],c[y]));
            x=t[x];
            y=t[y];
        }
        fout<<mx<<"\n";
    }
    return 0;
}
