#include<fstream>
#include<cstring>
#include<climits>
using namespace std;
ifstream cin("padure.in");
ofstream cout("padure.out");
int a[1001][1001],cost[1001][1001],n,m,li,lf,ci,cf,x,y,l,c,j,p,u;
short int q[2][1000010],q1[2][1000010],dx[]={-1,0,1,0},dy[]={0,1,0,-1};
bool viz[1001][1001];
void coada(int l1, int c1,int cost1)
{
    int p1=1,u1=1,i;
    q1[0][1]=l1;
    q1[1][1]=c1;
    while(p1<=u1)
    {
        int x1=q1[0][p1];
        int y1=q1[1][p1];
        for(int i=0;i<4;i++)
        {
            int ll=x1+dx[i];
            int cc=y1+dy[i];
            if(ll>0&&cc>0&&ll<=n&&cc<=m&&viz[ll][cc]==0&&a[ll][cc]==a[l1][c1])
            {
                    u1++;
                    q1[0][u1]=ll;
                    q1[1][u1]=cc;
                    cost[ll][cc]=cost1;
                    viz[ll][cc]=1;
                    u++;
                    q[0][u]=ll;
                    q[1][u]=cc;
            }
        }
        p1++;
    }
}
int main()
{
    int i;
    for(i=0;i<=n+1;i++)
        a[i][0]=a[i][m+1]=-1;
    for(j=0;j<=m+1;j++)
        a[0][j]=a[n+1][j]=-1;
    cin>>n>>m>>li>>ci>>lf>>cf;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    q[0][1]=li;
    q[1][1]=ci;
    p=u=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cost[i][j]=INT_MAX;
    cost[li][ci]=0;
    coada(li,ci,0);
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        for(i=0;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(l>0&&l<=n&&c>0&&c<=m&&viz[l][c]==0)
            {
                viz[l][c]=1;
                u++;
                q[0][u]=l;
                q[1][u]=c;
                cost[l][c]=cost[x][y]+1;
                coada(l,c,cost[l][c]);
            }
        }
        p++;
    }
    cout<<cost[lf][cf];
    return 0;
}
