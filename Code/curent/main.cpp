#include <fstream>
#include <algorithm>
#include <vector>

#define Ndim 100050
#define pb push_back
using namespace std;
ifstream fin("curent.in");
ofstream fout("curent.out");
int PAR[Ndim],N,M,T,A[Ndim],P[Ndim];
vector <int> G[Ndim];
bool STAT[Ndim];
struct strct{int day,hs,op;}V[2*Ndim];
bool cmp(const strct &a,const strct &b)
{
    return a.day<b.day;
}
void read()
{
    int x,i;
    fin>>N;
    for(i=1;i<N;i++)
    {
        fin>>x;
        G[x].pb(i+1);
        PAR[i+1]=x;
        A[i]=1;
    }
    A[N]=1;
    fin>>M;
    for(i=1;i<=M;i++)
    {
        fin>>V[i].day;
        fin>>V[i].hs;
        fin>>V[i].op;
    }
    fin>>T;
    for(;i<=T+M;i++)
    {
        fin>>V[i].day;
    }
}
void DFS(int nod)
{
    for(size_t i=0;i<G[nod].size();i++)
    {
        DFS(G[nod][i]);
        A[nod]+=A[G[nod][i]];
    }
}
void update(int nod)
{
    P[nod]=A[nod];
    for(size_t i=0;i<G[nod].size();i++)
        update(G[nod][i]);
}
void query(int nod)
{
    if(STAT[nod]==0)
    {
        P[nod]=0;
    }
    else
        return;
    for(size_t i=0;i<G[nod].size();i++)
    {
        query(G[nod][i]);
        P[nod]+=P[G[nod][i]];
    }
}
void solve()
{
    int i,j,psv,newu,newd,nod;
    sort(V+1,V+M+T+1,cmp);
    DFS(1);
    for(i=1;i<=T+M;i++)
    {
        if(V[i].hs==0)
        {
            fout<<A[1]-P[1]<<'\n';
            continue;
        }
        if(V[i].op==0)
        {
            newd=A[V[i].hs]-P[V[i].hs];
            STAT[V[i].hs]=1;
            update(V[i].hs);
            nod=PAR[V[i].hs];
            while(nod)
            {
                P[nod]+=newd;
                nod=PAR[nod];
            }
        }
        else
        {
            STAT[V[i].hs]=0;
            psv=P[V[i].hs];
            query(V[i].hs);
            newu=psv-P[V[i].hs];
            nod=PAR[V[i].hs];
            while(nod)
            {
                P[nod]-=newu;
                nod=PAR[nod];
            }
        }
    }
}
int main()
{
    read();
    solve();
    return 0;
}
