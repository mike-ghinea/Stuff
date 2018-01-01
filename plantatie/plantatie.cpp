#include<fstream>
#define pow(k) 1<<k
#define max(a,b,c,d) max(a,max(b,max(c,d)))
#define N 751
using namespace std;
ifstream cin("plantatie.in");
ofstream cout("plantatie.out");
int i,j,m,n,log[N],bst[10][N][N],p,k,x,y,z,t,T;
int main()
{
    cin>>n>>m;
    log[1]=0;
    for(i=2;i<=n;i++)
        log[i]=log[i/2]+1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>bst[0][i][j];
    for(i=1;i<=log[n];i++)
    {
        p=pow((i-1));
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                x=bst[i-1][j][k];
                y=bst[i-1][j][k+p];
                z=bst[i-1][j+p][k];
                t=bst[i-1][j+p][k+p];
                bst[i][j][k]=max(x,y,z,t);
            }
    }
    for(T=1;T<=m;T++)
    {
        cin>>i>>j>>k;
        p=pow((log[k]));
        x=bst[log[k]][i][j];
        y=bst[log[k]][i+k-p][j];
        z=bst[log[k]][i][j+k-p];
        t=bst[log[k]][i+k-p][j+k-p];
        cout<<max(x,y,z,t)<<"\n";
    }
    return 0;
}
