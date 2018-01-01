#include<fstream>
#include<limits.h>
#include<string.h>
using namespace std;
ifstream cin("insule.in");
ofstream cout("insule.out");
int q[2][10005],a[102][102],nr[5],n,m,dx[]={-1,0,1,0},dy[]={0,1,0,-1},viz[103][103],Min=10002;
char ch;
void coada(int x,int y,int k)
{
    int i,l,c;
    int p,u;
    p=u=1;
    q[0][1]=x;
    q[1][1]=y;
    a[x][y]=-k;
    while(p<=u)
    {
        for(i=0;i<=3;i++)
        {
            l=q[0][p]+dx[i];
            c=q[1][p]+dy[i];
            if(a[l][c]==k)
            {
                u++;
                q[0][u]=l;
                q[1][u]=c;
                a[l][c]=-k;
            }
        }
        p++;
    }

}
void coada1(int u)
{
    int i,l,c;
    int p;
    p=1;
    int ok=0;
    while(p<=u&&ok==0)
    {
        int xx=q[0][p];
        int yy=q[1][p];
        for(i=0;i<4;i++)
            {
                l=xx+dx[i];
                c=yy+dy[i];
                if(a[l][c]==0&&viz[l][c]==0)
                {
                    u++;
                    q[0][u]=l;
                    q[1][u]=c;
                    viz[l][c]=viz[xx][yy]+1;

                    }
                    else
                    if(a[l][c]==-2){
                      if(Min>viz[xx][yy]){
                          Min=viz[xx][yy];
                          ok=1;break;
                    }

                }
            }
            p++;
    }

}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>ch;
            a[i][j]=ch-'0';
        }
    for(i=0;i<=m+1;i++)
        a[0][i]=a[n+1][i]=-4;
    for(i=0;i<=n+1;i++)
        a[i][0]=a[i][m+1]=-4;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i][j]>0){
                nr[a[i][j]]++;
                coada(i,j,a[i][j]);
            }
        }
    for(i=1;i<=3;i++)
        cout<<nr[i]<<" ";
int u=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==-1){
              for(int t=0;t<4;t++){
                 int l=i+dx[t];
                 int c=j+dy[t];
                 if(a[l][c]==0&&viz[l][c]==0){
                    u++;
                    q[0][u]=l;
                    q[1][u]=c;
                    viz[l][c]=1;
                 }
              }
            }

        }
        coada1(u);
        cout<<Min;
    return 0;
}
