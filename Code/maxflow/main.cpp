#include <fstream>
#include <vector>
#include <string.h>
#include <limits.h>

#define NDIM 1003
#define INF INT_MAX
#define pb push_back
using namespace std;
ifstream fin("maxflow.in");
ofstream fout("maxflow.out");
int n,m,i,nod,fmin,flow,a,b,cost,c[NDIM][NDIM],q[NDIM*NDIM],f[NDIM][NDIM],par[NDIM],fiu;
bool viz[NDIM];
vector <int> G[NDIM];
int BFS()
{
    memset(viz,0,sizeof(viz));
    q[0]=q[1]=viz[1]=1;
    for(int i=1;i<=q[0];i++)
    {
        nod=q[i];
        if(nod==n) continue;
        for(size_t j=0;j<G[nod].size();j++)
        {
            fiu=G[nod][j];
            if(c[nod][fiu]==f[nod][fiu]||viz[fiu]) continue;
            viz[fiu]=1;
            par[fiu]=nod;
            q[++q[0]]=fiu;
        }
    }
    return viz[n];
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=m;i++)
    {
        fin>>a>>b>>cost;
        c[a][b]=cost;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(flow=0;BFS();)
    {
        for(i=0;i<G[n].size();i++)
        {
            fmin=INF;
            nod=G[n][i];
            if(c[nod][n]==f[nod][n]||!viz[nod]) continue;
            par[n]=nod;
            for(nod=n;nod!=1;nod=par[nod])
            {
                fmin=min(fmin,c[par[nod]][nod]-f[par[nod]][nod]);
            }
            if(fmin==0) continue;
            for(nod=n;nod!=1;nod=par[nod])
            {
                f[par[nod]][nod]+=fmin;
                f[nod][par[nod]]-=fmin;
            }
            flow+=fmin;
        }
    }
    fout<<flow;
    return 0;
}
