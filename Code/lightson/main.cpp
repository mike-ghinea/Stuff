#include <fstream>
#include <vector>
#define Ndim 105

using namespace std;
ifstream fin ("lightson.in");
ofstream fout ("lightson.out");
short int Q[2][Ndim*Ndim],u,p;
short int sol=1,n,m,j,i,x1,x2,y1,y2,x,y,l,c,viz[Ndim][Ndim],lx,cy;
short int const dx[]={-1,0,1,0},dy[]={0,1,0,-1};
vector < pair <short int,short int> > G[Ndim][Ndim];
int main()
{
    fin>>n>>m;
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
            viz[i][j]=1;
    }

    for(i=1;i<=m;i++)
    {
        fin>>x1>>y1>>x2>>y2;
        G[x1][y1].push_back(make_pair(x2,y2));
    }
    p=u=1;
    Q[0][1]=Q[1][1]=1;
    viz[1][1]=2;
    while(p<=u)
    {
        x=Q[0][p];
        y=Q[1][p];
        for(size_t i=0;i<G[x][y].size();i++)
        {
            l=G[x][y][i].first;
            c=G[x][y][i].second;
            if(viz[l][c]==1)
            {
                sol++;
                viz[l][c]=0;
                for(j=0;j<4;j++)
                {
                    lx=l+dx[j];
                    cy=c+dy[j];
                    if(viz[lx][cy]==2)
                    {
                        Q[0][++u]=l;
                        Q[1][u]=c;
                        viz[l][c]=2;
                    }
                }
            }
        }
        for(i=0;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(viz[l][c]==0)
            {
                Q[0][++u]=l;
                Q[1][u]=c;
                viz[l][c]=2;
            }
        }
        p++;
    }
    fout<<sol;
    return 0;
}
