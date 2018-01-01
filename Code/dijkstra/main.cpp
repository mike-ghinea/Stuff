#include <fstream>
#include <vector>

#define DIM 50001
#define inf 20000000
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
int n,m,i,j,d[DIM],H[DIM],poz[DIM],x,y,c,cost,dim,nod,k;
vector < pair <int,int> > G[DIM];
void up(int k)
{
    while(k/2>0)
    {
        if(d[H[k/2]]>d[H[k]])
        {
            swap(H[k/2],H[k]);
            swap(poz[H[k/2]],poz[H[k]]);
            k=k/2;
        }
        else
            break;
    }
}
void down()
{
    k=1;
    while(2*k<=dim)
    {
        int p=2*k;
        if(p+1<=dim and d[H[p]]>d[H[p+1]])
            p++;
        if(d[H[k]]>d[H[p]])
        {
             swap(H[k],H[p]);
             swap(poz[H[k]],poz[H[p]]);
             k=p;
        }
        else
            break;
    }
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=m;i++)
    {
        fin>>x>>y>>c;
        G[x].push_back(make_pair(y,c));
    }
    d[1]=0;
    H[++dim]=1;
    poz[1]=1;
    for(i=2;i<=n;i++)
        d[i]=inf;
    for(i=1;i<=n;i++)
    {
        nod=H[1];
        H[1]=H[dim];
        poz[H[1]]=1;
        dim--;
        down();
        for(j=0;j<G[nod].size();j++)
        {
            x=G[nod][j].first;
            cost=G[nod][j].second;
            if(d[x]>d[nod]+cost)
            {
                d[x]=d[nod]+cost;
                if(poz[x]==0)
                {
                    H[++dim]=x;
                    poz[x]=dim;
                    up(dim);
                }
                else
                {
                    up(poz[x]);
                }
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(d[i]!=inf)
            fout<<d[i]<<' ';
        else
            fout<<0<<' ';
    }
    return 0;
}
