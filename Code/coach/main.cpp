#include <fstream>
#include <limits.h>
#include <algorithm>
#include <string.h>

#define inf 2000000
#define dim 101
using namespace std;
ifstream fin("coach.in");
ofstream fout("coach.out");
int cost[dim][dim],i,j,k,s,n,m,t,cod[dim],a,b,c,cost1[dim][dim];
struct strct
{
    int x,y;
}v[dim];
int cmp(strct o,strct p)
{
    return o.x < p.x;
}
int main()
{
    fin>>n>>m>>t;
    for(i=1;i<=n;i++)
    {
        fin>>v[i].x;
        v[i].y=i;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        cod[v[i].y]=i;
    }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cost[i][j]=inf;
    for(i=1;i<=m;i++)
    {
        fin>>a>>b>>c;
        a=cod[a];
        b=cod[b];
        cost[a][b]=cost[b][a]=c;
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=n;j++)
//            fout<<cost[i][j]<<' ';
//        fout<<'\n';
//    }
    for(s=1;s<=n;s++)
    {
        memcpy(cost1,cost,sizeof(cost));
        for(k=s;k<=n;k++)
        {
            for(i=s;i<=n;i++)
            {
                for(j=s;j<=n;j++)
                {
                    if(i!=j && cost1[i][j]>cost1[i][k]+cost1[k][j])
                    {
                            cost1[i][j]=cost1[i][k]+cost1[k][j];
                    }
                    if(cost1[i][j]==t)
                    {
                        fout<<v[i].y<<' '<<v[j].y<<' '<<v[s].x<<' '<<max(max(v[i].x,v[j].x),v[k].x);
                        return 0;
                    }
                }
            }
//
//            fout<<s<<' '<<k<<'\n';
//            for(i=1;i<=n;i++)
//            {
//                for(j=1;j<=n;j++)
//                    if(cost1[i][j]==inf)
//                        fout<<0<<' ';
//                    else
//                    fout<<cost1[i][j]<<' ';
//                fout<<'\n';
//            }
//            fout<<'\n';

        }
    }
    return 0;
}
