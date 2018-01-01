#include <fstream>
#include <vector>
#include <string.h>

#define dim 100010
using namespace std;
ifstream fin("mvc.in");
ofstream fout("mvc.out");
int i,a,b,val[dim],ok,nod,vf1,vf2,n,sol1,sol2,dp[2][dim];
vector <int> G[dim];
bool viz[dim];
void DFS1(int x,int tata)
{
    viz[x]=1;
    if(ok==1)
        return;
    for(int i=0;i<G[x].size();i++)
    {
        nod=G[x][i];
        if(viz[nod]==0)
        {
            DFS1(nod,x);
        }
        else
        {
            if(nod!=tata)
            {
                vf1=nod;
                vf2=x;
                for(vector <int>::iterator it=G[vf2].begin();it<=G[vf2].end();it++)
                    if(*it==vf1)
                    {
                        G[vf2].erase(it);
                        break;
                    }
                for(vector <int>::iterator it=G[vf1].begin();it<=G[vf1].end();it++)
                    if(*it==vf2)
                    {
                        G[vf1].erase(it);
                        break;
                    }
                ok=1;
                return;
            }
        }
    }
}
void DFS(int x)
{
    viz[x]=1;
    for(int i=0;i<G[x].size();i++)
    {
        if(!viz[G[x][i]])
        {
            DFS(G[x][i]);
            dp[0][x]+=dp[1][G[x][i]];
            dp[1][x]+=min(dp[1][G[x][i]],dp[0][G[x][i]]);
        }

    }
    dp[1][x]+=val[x];
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>val[i];
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    DFS1(1,0);
    memset(viz,0,sizeof(viz));
    DFS(vf1);
    sol1=dp[1][vf1];
    memset(viz,0,sizeof(viz));
    memset(dp,0,sizeof(dp));
    DFS(vf2);
    sol2=min(sol1,dp[1][vf2]);
    fout<<min(sol1,sol2);
    return 0;
}
