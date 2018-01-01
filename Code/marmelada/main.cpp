#include <fstream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>

#define Ndim 100005
#define pb push_back
#define mkp make_pair
using namespace std;
ifstream fin("marmelada.in");
ofstream fout("marmelada.out");
int N,M,S,D,SOL[Ndim],DIST[Ndim],Mu[Ndim],POZ[Ndim],ind,Q[Ndim];
char Si[25];
vector <pair <int,int> > G[Ndim];
struct strct{int val,poz;}C[Ndim];
int cmp(strct a,strct b)
{
    return a.val<b.val;
}
void read()
{
    int i,a,b;
    fin>>N>>M>>S>>D;
    fin.get();
    for(i=1;i<=M;i++)
    {
        fin.getline(Si+1,20);
        int nr=0;
        int m=strlen(Si+1);
        for(int j=1;j<=m;j++)
            if(Si[j]>='0'&&Si[j]<='9')
                nr=nr*10+Si[j]-'0';
            else
                a=nr,nr=0;
        b=nr;
        G[a].pb(mkp(b,i));
        G[b].pb(mkp(a,i));
    }
    for(i=1;i<=M;i++)
    {
        fin>>C[i].val;
        C[i].poz=i;
    }
}
void BFS(int x)
{
    memset(DIST,-1,sizeof(DIST));
    DIST[x]=0;
    int p=1,u=1;
    Q[1]=x;
    while(p<=u)
    {
        x=Q[p];
        for(size_t i=0;i<G[x].size();i++)
        {
            int nod=G[x][i].first;
            if(DIST[nod]==-1)
            {
                DIST[nod]=DIST[x]+1;
                Q[++u]=nod;
            }
        }
        p++;
    }
}
void drum(int nod)
{
    if(nod==S)
        return;
    for(size_t i=0;i<G[nod].size();i++)
    {
        int x=G[nod][i].first;
        if(DIST[x]==DIST[nod]-1)
        {
            drum(x);
            SOL[G[nod][i].second]=C[++ind].poz;
        }
    }
}
void solve()
{
    BFS(S);
    sort(C+1,C+M+1,cmp);
    drum(D);
    for(int i=1;i<=M;i++)
        if(!SOL[i])
            SOL[i]=C[++ind].poz;
}
void print()
{
    for(int i=1;i<M;i++)
        fout<<SOL[i]<<'\n';
    fout<<SOL[M];
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
//////////
