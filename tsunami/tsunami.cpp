#include <fstream>
using namespace std;
ifstream cin("tsunami.in");
ofstream cout("tsunami.out");
int i,j,q[2][1000001],m,n,g,y,x,l,c,h,p,u,nr;
int a[1002][1002];
int main()
{
    cin>>n>>m>>h;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                q[0][++u]=i;
                q[1][u]=j;
            }
        }
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    for(i=0;i<=m+1;i++)
        a[0][i]=a[n+1][i]=-1;
    for(i=0;i<=n+1;i++)
        a[i][m+1]=a[i][0]=-1;
    g=u;
    p=1;
    a[q[0][1]][q[1][1]]=-1;
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        for(i=0;i<=3;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(a[l][c]!=-1&&a[l][c]<h)
            {
                if(a[l][c]!=0)
                nr++;
                a[l][c]=-1;
                q[0][++u]=l;
                q[1][u]=c;
            }
        }
        p++;
    }
    cout<<nr;
    return 0;
}
