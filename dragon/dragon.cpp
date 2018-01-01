#include <fstream>
#include <vector>
#include <queue>
#define inf 2000000000
using namespace std;
ifstream cin("dragoni.in");
ofstream cout("dragoni.out");
vector<pair<int,int> >G[801];
queue<int>Q[4];
bool viz[801];
int Pow[801],d[801],D[801],p,M,N,i,j,a,c,b,Max=-1;
class Dragon
{
public:
	dragon();
	~dragon();
	
};
int main()
{
    cin>>p;
    Dragon x;
	cin>>N>>M;
	for(i=1;i<=N;i++)
        cin>>Pow[i],
        d[i]=inf;
    D[1]=Pow[1];
    d[1]=0;
    for(i=1;i<=M;i++)
    {
        cin>>a>>b>>c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    if(p==1)
    {
        Q[0].push(1);
        Max=Pow[1];
        while(!Q[0].empty())
        {
            int node=Q[0].front();
            Q[0].pop();
            for(unsigned i=0;i<G[node].size();i++)
            {
                if(G[node][i].second<=Pow[1] and viz[G[node][i].first]==0)
                {
                    Max=max(Max,Pow[G[node][i].first]);
                    Q[0].push(G[node][i].first);
                    viz[G[node][i].first]=1;
                }
            }
        }
        cout<<Max;
        return 0;
    }
    Q[1].push(1);
    Q[2].push(0);
    Q[3].push(Pow[1]);
    while(!Q[1].empty())
    {
        int node=Q[1].front();
        int cost=Q[2].front();
        int drgn=Q[3].front();
        Q[1].pop();
        Q[2].pop();
        Q[3].pop();
        for(unsigned i=0;i<G[node].size();i++)
        {
            int curr=G[node][i].first;
            int drum=G[node][i].second;
            if(drum>drgn)
                continue;
            if(d[curr]>drum+cost or drgn>D[curr])
            {
                d[curr]=min(d[curr],drum+cost);
                D[curr]=max(D[curr],max(drgn,Pow[curr]));
                Q[1].push(curr);
                Q[2].push(drum+cost);
                Q[3].push(max(Pow[curr],drgn));
            }
        }
    }
    cout<<d[N];
}
