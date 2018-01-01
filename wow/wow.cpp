#include<fstream>
#include<cstring>
#include<climits>
using namespace std;
ifstream cin("wow.in");
ofstream cout("wow.out");
int n,p,m,j,x,y,a[101][101],b[101][101],f[101][101],viz[101][101],l,c,k,Min=INT_MAX;
short int q[2][10001],dx[]={0,1,0,-1},dy[]={-1,0,1,0};
void coada(int x,int y,int nr)
{
    int i,k=1,u=1;
    memset(b,0,sizeof(b));
    q[0][1]=x;
    q[1][1]=y;
    viz[x][y]++;
    b[x][y]=1;
    f[x][y]+=b[x][y];
    while(k<=u)
    {
        for(i=0;i<=3;i++)
        {
            l=q[0][k]+dx[i];
            c=q[1][k]+dy[i];
            if(a[l][c]!=-1&&l>=0&&l<n&&c>=0&&c<p&&viz[l][c]<nr)
            {
                viz[l][c]++;
                b[l][c]=b[q[0][k]][q[1][k]]+1;
                f[l][c]+=b[l][c];
                u++;
                q[0][u]=l;
                q[1][u]=c;
            }
        }
        k++;
    }
}
int main()
{
    int i;
    cin>>n>>p>>m;
    for(i=0;i<=n-1;i++)
        for(j=0;j<=p-1;j++)
        {
            cin>>a[i][j];
            a[i][j]*=-1;
        }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        coada(x,y,i);
    }
    for(i=0;i<=n-1;i++)
        for(j=0;j<=p-1;j++)
            if(f[i][j])
            Min=min(Min,f[i][j]);
    cout<<Min-m<<"\n";
    for(i=0;i<=n-1;i++)
        for(j=0;j<=p-1;j++)
        if(viz[i][j]==m&&f[i][j]==Min)
        {
            cout<<i<<" "<<j;
            return 0;
        }

}
