#include<fstream>
#include<vector>
#include<climits>
#define N 200002
#define pb push_back
#define mk make_pair
#define INF LONG_LONG_MAX
#define foreach(i,n,v) for(int i=v;i<=n;i++)
using namespace std;
ifstream cin("autobuze3.in");
ofstream cout("autobuze3.out");
vector < pair <int,int> > G[2*N];
int main()
{
    cin>>T;
    foreach(t,T,1)
    {
        cin>>n>>m;
        foreach(i,m,1)
            G[i].clear();
        foreach(i,m,1)
        {
            cin>>x>>y>>c;
            G[x].pb(mp(y,c));
            G[y].pb(mp(x,c));
        }
        foreach(i,n,2)
            v[i]=INF;
        v[1]=0;
    }
    return 0;
}
