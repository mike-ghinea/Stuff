#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>

#define Ndim 50005
#define Kdim 100005
#define pb push_back
using namespace std;
ifstream fin("maxflow.in");
ofstream fout("maxflow.out");
int N,K,PAR[Ndim],NIV[2*Ndim],F[Ndim],SOL[Ndim],H[2*Ndim],rmq[21][2*Ndim],k,First[Ndim],lg[2*Ndim];
bool VIZ[Ndim];
struct strct {int x,y;}V[Kdim];
vector <int> G[Ndim];
void read()
{
    int i,a,b;
    fin>>N>>K;
    for(i=1;i<N;i++)
    {
        fin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(i=1;i<=K;i++)
    {
        fin>>V[i].x>>V[i].y;
    }
}
void DFS(int nod,int grad)
{
    VIZ[nod]=1;
    H[++k]=nod;
    NIV[k]=grad;
    First[nod] = k;
    for(size_t i=0;i<G[nod].size();i++)
    {
        if(VIZ[G[nod][i]]==0)
        {
            VIZ[G[nod][i]]=1;
            PAR[G[nod][i]]=nod;
            DFS(G[nod][i],grad+1);
            H[++k]=nod;
            NIV[k]= grad;
        }
    }
}
void RMQ()
{
    int i,j;
    for(i=2;i<=k;i++)
        lg[i]=lg[i>>1]+1;
    for(i=1;i<=k;i++)
        rmq[0][i]=i;
    for(i=1;(1<<i)<k;i++)
        for(j=1;j<=k-(1<<i);j++)
        {
            rmq[i][j]=rmq[i-1][j];
            if(NIV[rmq[i-1][j+(1<<(i-1))]]< NIV[rmq[i][j]])
                rmq[i][j] = rmq[i-1][j+(1<<(i-1))];
        }
}
int lca(int x,int y)
{
    int d,l,sol,sh;
    x=First[x];y=First[y];
    if(x > y)
        swap(x,y);
    d=y-x+1;
    l=lg[d];
    sol=rmq[l][x];
    sh=d-(1<<l);
    if(NIV[sol]>NIV[rmq[d][x+sh]])
        sol=rmq[d][x+sh];
    return H[sol];
}
void DFS2(int nod)
{
    VIZ[nod]=1;
    SOL[nod]+=F[nod];
    for(size_t i=0;i<G[nod].size();i++)
    {
        if(!VIZ[G[nod][i]])
        {
            VIZ[G[nod][i]]=1;
            DFS2(G[nod][i]);
            SOL[nod]+=SOL[G[nod][i]];
        }
    }
}
void solve()
{
    int i,a,b,val,nod;
    for(i=1;i<=K;i++)
    {
        a=V[i].x;
        b=V[i].y;
        nod=lca(a,b);
        F[a]++;
        F[b]++;
        F[nod]--;
        F[PAR[nod]]--;
    }
    memset(VIZ,0,sizeof(VIZ));
    DFS2(1);
}
void print()
{
    int i,sol=0;
    for(i=1;i<=N;i++)
        sol=max(sol,SOL[i]);
    fout<<sol;
}
int main()
{
    read();
    NIV[0]=Ndim+10;
    DFS(1,1);
    RMQ();
    solve();
    print();
    return 0;
}
