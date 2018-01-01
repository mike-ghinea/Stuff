#include <fstream>
#include <vector>
#include <string.h>

#define dim 16001

using namespace std;
ifstream fin("razboi.in");
ofstream fout("razboi.out");
short int i,t,te, n,nr,v[2][dim],a,b,c,first,fiu,sol[dim];
int x, dist[2][dim];
bool viz[dim];
vector <short int> fii[dim],cost[dim];
int DFSD(short int nod,short int tata,short int nr)
{
    viz[nod]=1;
    for(int i=0; i< fii[nod].size();i++)
    {
        if(viz[fii[nod][i]]==1)
            continue;
        x=DFSD(fii[nod][i],nod,i);
        if(x>=dist[0][nod])
        {
            dist[1][nod]=dist[0][nod];
            dist[0][nod]=x;
            v[1][nod]=v[0][nod];
            v[0][nod]=fii[nod][i];
        }
        else
        {
            if(x>=dist[1][nod])
            {
                dist[1][nod]=x;
                v[1][nod]=fii[nod][i];
            }
        }

    }
    if (nod == first)
        return 0;
    return dist[0][nod] + cost[tata][nr];
}
void DFSU(int nod)
{
    viz[nod]=1;
    for(int i=0; i<fii[nod].size();i++)
    {
        if(viz[fii[nod][i]]==1)
            continue;
        fiu=fii[nod][i];
        if(v[0][nod]!=fiu)
        {
            if(dist[0][fiu]<dist[0][nod]+cost[nod][i])
            {
                dist[1][fiu]=dist[0][fiu];
                v[1][fiu]=v[0][fiu];
                dist[0][fiu]=dist[0][nod]+cost[nod][i];
                v[0][fiu]=nod;
            }
            else
            {
               if(dist[1][fiu]<dist[0][nod]+cost[nod][i])
                {
                    dist[1][fiu]=dist[0][nod]+cost[nod][i];
                    v[1][fiu]=nod;
                }
            }
        }
        else
        {
            if(dist[0][fiu]<dist[1][nod]+cost[nod][i])
            {
                dist[1][fiu]=dist[0][fiu];
                v[1][fiu]=v[0][fiu];
                dist[0][fiu]=dist[1][nod]+cost[nod][i];
                v[0][fiu]=nod;
            }
            else
            {
               if(dist[1][fiu]<dist[1][nod]+cost[nod][i])
                {
                    dist[1][fiu]=dist[1][nod]+cost[nod][i];
                    v[1][fiu]=nod;
                }
            }
        }
        DFSU(fiu);
    }
    return;
}
int main()
{
    fin>>t;

    for(te=1;te<=t;te++)
    {
        fin>>n;
        fin>>a>>b>>c;
        memset(fii,0,sizeof(fii));
        memset(dist,0,sizeof(dist));
        memset(viz,0,sizeof(viz));
        memset(cost,0,sizeof(cost));
        dist[0][0]=900000000;
        fii[a].push_back(b);
        fii[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
        first = a;
        for(i=2;i<n;i++)
        {
            fin>>a>>b>>c;
            fii[a].push_back(b);
            fii[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        a=DFSD(first,0,0);
        memset(viz,0,sizeof(viz));
        DFSU(first);
        nr=0;
        sol[0]=0;
        for(i=1;i<=n;i++)
        {
            if(dist[0][i]<dist[0][sol[nr]])
            {
                nr=0;
                sol[++nr]=i;
            }
            else
                if(dist[0][i]==dist[0][sol[nr]])
                {
                    sol[++nr]=i;
                }
        }
        fout<<"Testul nr #"<<te<<'\n';
        for(i=1;i<=nr;i++)
            fout<<sol[i]<<'\n';
    }
    fout<<'\n';
    return 0;
}
