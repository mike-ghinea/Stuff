#include<fstream>
#include<vector>
#define N 50001
using namespace std;
ifstream cin("sortaret.in");
ofstream cout("sortaret.out");
vector <int> G[N];
int v[N],i,m,n,a,nr,b;
bool viz[N];
void dfs(int nod)
{
    viz[nod]=1;
    for(int i=0;i<(int)G[nod].size();i++)
        if(!viz[G[nod][i]])
            dfs(G[nod][i]);
    v[++nr]=nod;
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
    }
    for(i=1;i<=n;i++)
        if(!viz[i])
            dfs(i);
    while(nr--)
        cout<<v[nr+1]<<" ";
    return 0;
}
