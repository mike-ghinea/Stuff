#include<fstream>
#include<vector>
#define N 200004
#define pow(k) 1<<k
using namespace std;
ifstream cin("lca.in");
ofstream cout("lca.out");
vector <int> arb[N/2];
int n,m,nr,p[N],q[20][N],log[N],j,c,d,a,b,i,t;
void dfs(int nod)
{
    q[0][++nr]=nod;
    if(!p[nod])
        p[nod]=nr;
    for(int i=0;i<(int)arb[nod].size();i++)
    {
        c=arb[nod][i];
        dfs(c);
        q[0][++nr]=nod;
    }
}
int main()
{
    cin>>n>>m;
    for(i=2;i<=n;i++)
    {
        cin>>t;
        arb[t].push_back(i);
    }
    dfs(1);
    log[1]=0;
    for(i=2;i<=nr;i++)
        log[i]=log[i/2]+1;
    for(i=1;(pow(i))<=nr;i++)
        for(j=1;j<=nr;j++)
            q[i][j]=min(q[i-1][j],q[i-1][j+(pow((i-1)))]);
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(p[a]>p[b])
            swap(a,b);
        d=log[p[b]-p[a]];
        cout<<min(q[d][p[a]],q[d][p[b]-(pow(d))+1])<<"\n";
    }
}
