#include <fstream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <algorithm>

#define NDIM 1003
#define MDIM 10003
#define INF INT_MAX
#define pb push_back
using namespace std;
ifstream fin("critice.in");
ofstream fout("critice.out");
int PAR[NDIM],F[NDIM][NDIM],POZ[NDIM][NDIM],C[NDIM][NDIM],Q[NDIM],SOL[10*NDIM],nr,N,M,vx[MDIM],vy[MDIM];
bool VIZ[NDIM],VIZ1[2][NDIM];
vector <int> G[NDIM];
int BFS()
{
    memset(VIZ,0,sizeof(VIZ));
    Q[0]=Q[1]=VIZ[1]=1;
    int x,nod;
    for(int i=1;i<=Q[0];i++)
    {
        x=Q[i];
        for(size_t j=0;j<G[x].size();j++)
        {
            nod=G[x][j];
            if(C[x][nod]==F[x][nod]||VIZ[nod]) continue;
            PAR[nod]=x;
            VIZ[nod]=1;
            Q[++Q[0]]=nod;
            if(nod==N)
                return 1;
        }
    }
    return 0;
}
void BFS1()
{
    Q[0]=Q[1]=VIZ1[0][1]=1;
    int x,nod;
    for(int i=1;i<=Q[0];i++)
    {
        x=Q[i];
        for(size_t j=0;j<G[x].size();j++)
        {
            nod=G[x][j];
            if(VIZ1[0][nod]==0 && C[x][nod]>F[x][nod] && C[x][nod]>F[nod][x])
            {
                VIZ1[0][nod]=1;
                Q[++Q[0]]=nod;
            }
        }
    }

}
void BFSN()
{
    Q[0]=1;
    Q[1]=N;
    VIZ1[1][N]=1;
    int x,nod;
    for(int i=1;i<=Q[0];i++)
    {
        x=Q[i];
        for(size_t j=0;j<G[x].size();j++)
        {
            nod=G[x][j];
            if(VIZ1[1][nod]==0 && C[x][nod]>F[x][nod] && C[x][nod]>F[nod][x])
            {
                VIZ1[1][nod]=1;
                Q[++Q[0]]=nod;
            }
        }
    }
}

int main()
{
    int i,a,b,cost,nod,fmin,flow,x,y;
    fin>>N>>M;
    for(i=1;i<=M;i++)
    {
        fin>>a>>b>>cost;
        C[a][b]=C[b][a]=cost;
        POZ[a][b]=POZ[b][a]=i;
        G[a].pb(b);
        G[b].pb(a);
        vx[i]=a;
        vy[i]=b;
    }
    for(flow=0;BFS();)
    {
        for(size_t i=0;i<G[N].size();i++)
        {
            nod=G[N][i];
            fmin = INF;
            if(C[PAR[nod]][nod]==F[PAR[nod]][nod]||!VIZ[nod]) continue;
            PAR[N]=nod;
            for(nod=N;nod!=1;nod=PAR[nod])
                fmin=min(fmin,C[PAR[nod]][nod]-F[PAR[nod]][nod]);
            if(fmin==0) continue;
            for(nod=N;nod!=1;nod=PAR[nod])
            {
                F[PAR[nod]][nod]+=fmin;
                F[nod][PAR[nod]]-=fmin;
            }
            flow+=fmin;
        }
    }
    BFS1();
    BFSN();
    for(i=1;i<=M;i++)
    {
        x=vx[i];y=vy[i];
        if(C[x][y]==F[x][y] || C[y][x]==F[y][x])
        {
            if((VIZ1[0][x]==1 && VIZ1[1][y]==1)||(VIZ1[0][y]==1 && VIZ1[1][x]==1))
            {
                SOL[++nr]=i;
            }
        }
    }
    fout<<nr<<'\n';
    for(i=1;i<=nr;i++)
        fout<<SOL[i]<<'\n';
    return 0;
}
