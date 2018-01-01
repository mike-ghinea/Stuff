#include<fstream>
#include<vector>
#include<climits>
#define N 1002
#define INF INT_MAX
#define pb(x) push_back(x)
using namespace std;
ifstream cin("maxflow.in");
ofstream cout("maxflow.out");
bool viz[N];
int F[N][N],T[N],C[N][N],n,m,x,y,z,flow,Min,nod,v,q[N*N];
vector <int> G[N];
int bfs()
{
    for(int i=1;i<=n;i++)
        viz[i]=0;
    q[0]=1;
    q[1]=1;
    viz[1]=1;
    for(int i=1;i<=q[0];i++)
    {
        nod=q[i];
        if(nod==n)
            continue;
        for(size_t j=0;j<G[nod].size();j++)
        {
            v=G[nod][j];
            if(viz[v] or C[nod][v]==F[nod][v])
                continue;
            viz[v]=1;
            T[v]=nod;
            q[++q[0]]=v;
        }
    }
    return viz[n];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        G[x].pb(y);
        G[y].pb(x);
        C[x][y]=z;
    }
    while(bfs())
    {
        for(size_t i=0;i<G[n].size();i++)
        {
            Min=INF;
            nod=G[n][i];
            if(!viz[nod] or C[nod][n]==F[nod][n])
                continue;
            T[n]=nod;
            for(nod=n;nod!=1;nod=T[nod])
                Min=min(Min,C[T[nod]][nod]-F[T[nod]][nod]);
            if(Min==0)
                continue;
            for(nod=n;nod!=1;nod=T[nod])
            {
                F[T[nod]][nod]+=Min;
                F[nod][T[nod]]-=Min;
            }
            flow+=Min;
        }
    }
    cout<<flow;
    return 0;
}
