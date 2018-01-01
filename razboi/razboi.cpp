#include<fstream>
#include<vector>
#include<cstring>
#include<climits>
#define dim 16001
#define inf INT_MAX
using namespace std;
ifstream cin("razboi.in");
ofstream cout("razboi.out");
short i,t,T,n,nr,v[2][dim],a,b,c,first,son,sol[dim];
int x,dist[2][dim];
bool viz[dim];
vector <short> sons[dim],cost[dim];
int dfs1(short nod,short father,short nr)
{
    viz[nod]=1;
    for(unsigned i=0;i<sons[nod].size();i++)
    {
        if(viz[sons[nod][i]]==1)
            continue;
        x=dfs1(sons[nod][i],nod,i);
        if(x>=dist[0][nod])
        {
            dist[1][nod]=dist[0][nod];
            dist[0][nod]=x;
            v[1][nod]=v[0][nod];
            v[0][nod]=sons[nod][i];
        }
        else
        {
            if(x>=dist[1][nod])
            {
                dist[1][nod]=x;
                v[1][nod]=sons[nod][i];
            }
        }
    }
    if (nod==first)
        return 0;
    return dist[0][nod]+cost[father][nr];
}
void dfs2(int nod)
{
    viz[nod]=1;
    for(unsigned i=0;i<sons[nod].size();i++)
    {
        if(viz[sons[nod][i]])
            continue;
        son=sons[nod][i];
        if(v[0][nod]!=son)
        {
            if(dist[0][son]<dist[0][nod]+cost[nod][i])
            {
                dist[1][son]=dist[0][son];
                v[1][son]=v[0][son];
                dist[0][son]=dist[0][nod]+cost[nod][i];
                v[0][son]=nod;
            }
            else if(dist[1][son]<dist[0][nod]+cost[nod][i])
            {
                    dist[1][son]=dist[0][nod]+cost[nod][i];
                    v[1][son]=nod;
            }
        }
        else
        {
            if(dist[0][son]<dist[1][nod]+cost[nod][i])
            {
                dist[1][son]=dist[0][son];
                v[1][son]=v[0][son];
                dist[0][son]=dist[1][nod]+cost[nod][i];
                v[0][son]=nod;
            }
            else if(dist[1][son]<dist[1][nod]+cost[nod][i])
            {
                dist[1][son]=dist[1][nod]+cost[nod][i];
                v[1][son]=nod;
            }
        }
        dfs2(son);
    }
    return;
}
int main()
{
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        cin>>a>>b>>c;
        memset(sons,0,sizeof(sons));
        memset(dist,0,sizeof(dist));
        memset(viz,0,sizeof(viz));
        memset(cost,0,sizeof(cost));
        dist[0][0]=inf;
        sons[a].push_back(b);
        sons[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
        first=a;
        for(i=2;i<n;i++)
        {
            cin>>a>>b>>c;
            sons[a].push_back(b);
            sons[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        a=dfs1(first,0,0);
        memset(viz,0,sizeof(viz));
        dfs2(first);
        nr=0;
        sol[0]=0;
        for(i=1;i<=n;i++)
        {
            if(dist[0][i]<dist[0][sol[nr]])
            {
                nr=0;
                sol[++nr]=i;
            }
            else if(dist[0][i]==dist[0][sol[nr]])
                sol[++nr]=i;
        }
        cout<<"Testul nr #"<<t<<'\n';
        for(i=1;i<=nr;i++)
            cout<<sol[i]<<'\n';
    }
    return 0;
}
