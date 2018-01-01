#include <fstream>
using namespace std;
ifstream cin("derdelus.in");
ofstream cout("derdelus.out");
int bst[1001][1001],a[1001][1001],c[1001][1001],d[1001][1001],i,j,k,n,m,p,x,y;
int main()
{
    cin>>n>>m>>p;
    for(i=1;i<=p;i++)
    {
        cin>>x>>y;
        a[x][y]=-1;
    }
    bst[1][1]=c[1][1]=d[1][1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(a[i][j]!=-1)
            {
                k=m;
                if(i-k-1<0)
                    k=i-1;
                bst[i][j]=(c[i-1][j]-c[i-k-1][j])%666013;
                if(bst[i][j]<0)
                    bst[i][j]+=666013;
                k=m;
                if(j-k-1<0)
                    k=j-1;
                bst[i][j]=(bst[i][j]+d[i-1][j-1]-d[i-k-1][j-k-1])%666013;
                if(bst[i][j]<0)
                    bst[i][j]+=666013;
            }
            c[i][j]=c[i-1][j]+bst[i][j];
            c[i][j]%=666013;
            d[i][j]=d[i-1][j-1]+bst[i][j];
            d[i][j]%=666013;
        }
    }
    for(i=1;i<=n;i++)
        cout<<bst[n][i]<<' ';
    return 0;
}
