#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>

#define Ndim 400+10
#define nrnodmax 400
#define inf 300*2000+10
#define pb push_back
using namespace std;
ifstream fin("furtuna.in");
ofstream fout("furtuna.out");

short int N,M,T,c,C[Ndim][Ndim],F[Ndim][Ndim],PAR[Ndim],Q[Ndim],cab[104],valcab[404],start = 401,dest=402,nr,nodleg,d[401][401],tur[101];
bool VIZ[Ndim],VIZN[Ndim];
vector <short int> G[Ndim];
struct strct1{short int val,start,finish;}v[100010];
bool cmp(const strct1 &a, const strct1 &b)
{
    return a.val<b.val;
}
void read()
{
    fin>>N>>M>>T>>c;
    short int x,y,dist;
    for(int i=1;i<=M;i++)
    {
        fin>>x>>y>>dist;
        d[x][y]=dist;
        d[y][x]=dist;
    }
    for(int i=1;i<=T;i++)
        fin>>tur[i];
    for(int i=1;i<=c;i++)
    {
        fin>>cab[i];
        fin>>valcab[cab[i]];
    }
}
void royfloyd()
{
    int i,j,k;
    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                if(d[i][k] && d[k][j] && (d[i][j] > d[i][k] + d[k][j] || !d[i][j]) && i!=j)
                    d[i][j]=d[i][k]+d[k][j];
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            if(d[i][j]==0)
                d[i][j]=inf;
    }
//    for(i=1;i<=N;i++)
//    {
//        for(j=1;j<=N;j++)
//            fout<<d[i][j]<<' ';
//        fout<<'\n';
//    }
}
int BFS()
{
    memset(VIZ,0,sizeof(VIZ));
    int p=1,u=1,x,nod;
    Q[1]=start;
    VIZ[start]=1;
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
            VIZ[nod]=1;
            Q[++u]=nod;
            PAR[nod]=x;
        }
        p++;
    }
    return VIZ[dest];
}
int maxflow(int val)
{
    int i,nod,fmin,flow=0;
    for(i=1;i<=Ndim;i++)
        G[i].clear();
    memset(VIZN,0,sizeof(VIZN));
    memset(F,0,sizeof(F));
    memset(PAR,0,sizeof(PAR));
    for(i=1;v[i].val<=val&&i<=nr;i++)
    {
        if(!VIZN[v[i].start])
        {
            G[start].pb(v[i].start);
            G[v[i].start].pb(start);
            VIZN[v[i].start]=1;
            C[start][v[i].start]=1;
        }
        G[v[i].start].pb(v[i].finish);
        G[v[i].finish].pb(v[i].start);
        C[v[i].start][v[i].finish]=1;
        if(!VIZN[v[i].finish])
        {
            VIZN[v[i].finish]=1;
            G[v[i].finish].pb(dest);
            G[dest].pb(v[i].finish);
            C[v[i].finish][dest]=valcab[v[i].finish];
        }
    }
    while(BFS())
    {
        for(size_t i=0;i<G[dest].size();i++)
        {
            nod=G[dest][i];
            if(C[nod][dest]==F[nod][dest]||!VIZ[nod])
                continue;
            PAR[dest]=nod;
            fmin=C[nod][dest]-F[nod][dest];
            for(;nod!=start;nod=PAR[nod])
                fmin=min(fmin,C[PAR[nod]][nod]-F[PAR[nod]][nod]);
            if(fmin==0)
                continue;
            for(nod=dest;nod!=start;nod=PAR[nod])
            {
                F[PAR[nod]][nod]+=fmin;
                F[nod][PAR[nod]]-=fmin;
            }
            flow+=fmin;
        }
    }
    return flow == T;
}
int main()
{
    int i,j;
    read();
    royfloyd();
    for(i=1;i<=T;i++)
        for(j=1;j<=c;j++)
        {
            v[++nr].val=d[tur[i]][cab[j]];
            v[nr].start=tur[i];
            v[nr].finish=cab[j];
        }
    sort(v+1,v+nr+1,cmp);
    int st=1,dr=inf,mij=(st+dr)/2,sol=inf;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(maxflow(mij))
        {
            sol=min(sol,mij);
            dr=mij-1;
        }
        else
            st=mij+1;
    }
    fout<<sol;
    return 0;
}
