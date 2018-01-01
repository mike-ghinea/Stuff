#include <fstream>
#include <vector>

#define DIM 100010
using namespace std;
ifstream fin("reinvent.in");
ofstream fout("reinvent.out");
int n,m,x,i,a,b,nod,sol,q[DIM],d[DIM],poz[DIM],u,p,OK;
vector <int> G[DIM];
int main()
{
    fin>>n>>m>>x;
    for(i=1;i<=m;i++)
    {
        fin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=1;i<=x;i++)
    {
        fin>>a;
        q[++u]=a;
        poz[a]=a;
    }
    p=1;
    OK=1;
    while(OK)
    {
        nod=q[p];
        for(i=0;i<G[nod].size();i++)
        {
            x=G[nod][i];
            if(poz[x]==0)
            {
                poz[x]=poz[nod];
                d[x]=d[nod]+1;
                q[++u]=x;
            }
            else
            {
                if(poz[x]!=poz[nod])
                {
                    sol=d[x]+d[nod]+1;
                    OK=0;
                    break;
                }
            }
        }
        p++;
    }
    fout<<sol;
    return 0;
}
