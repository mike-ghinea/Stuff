#include <fstream>
#include <string.h>
#include <vector>

#define Ndim 203
#define pb push_back
using namespace std;
ifstream fin("harta.in");
ofstream fout("harta.out");
int N,sursa,dest,C[Ndim][Ndim],F[Ndim][Ndim],PAR[Ndim],Q[Ndim];
bool VIZ[Ndim];
vector <int> G[Ndim];
int BFS()
{
    memset(VIZ,0,sizeof(VIZ));
    memset(PAR,0,sizeof(PAR));
    int p=1,u=1,nod,x;
    Q[1]=sursa;
    VIZ[sursa]=1;
    while(p<=u)
    {
        x=Q[p];
        if(x==dest)
        {
            p++;
            continue;
        }
        for(size_t i=0;i<G[x].size();i++)
        {
            nod=G[x][i];
            if(C[x][nod]==F[x][nod]||VIZ[nod])
                continue;
            PAR[nod]=x;
            VIZ[nod]=1;
            Q[++u]=nod;
        }
        p++;
    }
    return VIZ[dest];
}
void maxflow()
{

    int nod,x,fmin;
    while(BFS())
    {
        for(size_t i=0;i<G[dest].size();i++)
        {
            nod=G[dest][i];
            if(C[nod][dest]==F[nod][dest]||!VIZ[nod])
                continue;
            x=nod;
            PAR[dest]=nod;
            fmin=C[nod][dest]-F[nod][dest];
            if(fmin==0)
                continue;
            for(nod=x;nod!=sursa;nod=PAR[nod])
                fmin=min(C[PAR[nod]][nod]-F[PAR[nod]][nod],fmin);
            if(fmin==0)
                continue;
            for(nod=dest;nod!=sursa;nod=PAR[nod])
            {
                F[PAR[nod]][nod]+=fmin;
                F[nod][PAR[nod]]-=fmin;
            }
            //flux+=fmin;
        }
    }
}
int main()
{
    fin>>N;sursa=201;dest=202;
    int i,a,b,sum=0,j;
    for(i=1;i<=N;i++)
    {
        fin>>a>>b;
        sum+=b;
        C[sursa][i]=a;
        C[i+100][dest]=b;
        G[sursa].pb(i);
        G[i].pb(sursa);
        G[i+100].pb(dest);
        G[dest].pb(i+100);
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i==j)
                continue;
            C[i][j+100]=1;
            G[i].pb(j+100);
            G[j+100].pb(i);
        }
    }
    maxflow();
    fout<<sum<<'\n';
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
        {
            if(i==j)
                continue;
            if(F[i][j+100]==1)
                fout<<i<<' '<<j<<'\n';
        }
    return 0;
}
