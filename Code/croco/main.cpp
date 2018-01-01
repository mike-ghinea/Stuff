#include <fstream>
#include <vector>
#include <string.h>

#define Ndim 111
#define pb push_back
using namespace std;
ifstream fin("croco.in");
ofstream fout("croco.out");
int N,finish,PAR[Ndim],C[Ndim][Ndim],F[Ndim][Ndim],Q[Ndim];
bool VIZ[Ndim];
vector <int> G[Ndim];
int BFS()
{
    memset(VIZ,0,sizeof(VIZ));
    memset(PAR,0,sizeof(PAR));
    VIZ[1]=1;
    int p=1,u=1,nod,x;
    Q[1]=1;
    while(p<=u)
    {
        x=Q[p];
        if(x==finish)
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
    return VIZ[finish];
}
int maxflow()
{
    memset(F,0,sizeof(F));
    int nod,flux=0,x,fmin;
    while(BFS())
    {
        for(size_t i=0;i<G[finish].size();i++)
        {
            nod = G[finish][i];
            if(C[nod][finish]==F[nod][finish]||!VIZ[nod])
                continue;
            x=nod;
            PAR[finish]=x;
            fmin=C[nod][finish]-F[nod][finish];
            for(nod=x;nod!=1;nod=PAR[nod])
                fmin=min(C[PAR[nod]][nod]-F[PAR[nod]][nod],fmin);
            if(fmin==0)
                continue;
            F[x][finish]+=fmin;
            F[finish][x]-=fmin;
            for(nod=x;nod!=1;nod=PAR[nod])
            {
                F[PAR[nod]][nod]+=fmin;
                F[nod][PAR[nod]]-=fmin;
            }
            flux+=fmin;
        }
    }
    return flux;
}
int main()
{
    int flmin=222*110*110,val,sum=0,i,j,x,nodf,nrnod=0;
    fin>>N;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
        {
            fin>>x;
            if(j<=i)
                continue;
            C[i][j]=C[j][i]=x;
            if(x)
            {
                G[i].pb(j);
                G[j].pb(i);
                sum+=x;
            }
        }
    for(i=2;i<=N;i++)
    {
        finish=i;
        val=maxflow();
        if(val<flmin)
        {
            flmin=val;
            nodf=i;
        }
    }
    finish = nodf;
    flmin = maxflow();
    for(i=1;i<=N;i++)
        if(VIZ[i])
            nrnod++;
    fout<<sum-flmin<<' '<<nrnod<<'\n';
    for(i=1;i<=N;i++)
        if(VIZ[i])
            fout<<i<<' ';
    return 0;
}
