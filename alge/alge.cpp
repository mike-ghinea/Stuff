#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("alge.in");
ofstream cout("alge.out");
char a[37][37][37],d[37][37][37],q[3][46657];
short int dx[]={0,0,0,0,0,1,-1},dy[]={0,0,0,1,-1,0,0,},dz[]={0,-1,1,0,0,0,0},n,m,x,y,z,,i,j,k;
int main()
{
    memset(a,'1',sizeof(a));
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y][z]='0';
    }
    for(i=0;i<=n+1;i++)
        for(j=0;j<=n+1;j++)
        {
            a[i][j][0]=a[i][j][n+1]=a[0][j][i]=a[n+1][j][i]=-1;
            a[0][i][j]=a[n+1][i][j]=a[i][0][j]=a[i][n+1][j]=-1;
        }
    int p,u;
    p=u=1;
    q[0][1]=1;
    q[1][1]=1;
    q[2][1]=1;
    while(p<=u)
    {

    }
    /*for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
        {
            for(k=0;k<=n+1;k++)
                cout<<a[i][j][k]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        }*/
    return 0;
}
