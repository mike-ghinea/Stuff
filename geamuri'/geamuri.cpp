#include <fstream>
using namespace std;
ifstream cin("geamuri.in");
ofstream cout("geamuri.out");
int x,xx,y,yy,i,j,t,k,m,n,c,v[50111],a[1026][1026],s;
int main()
{
    cin>>c>>n;
    for(t=1;t<=n;t++)
    {
        cin>>x>>y>>xx>>yy;
        a[x][y]++;
        a[xx+1][yy+1]++;
        a[xx+1][y]--;
        a[x][yy+1]--;
    }
    for(i=1;i<=c;i++)
        for(j=1;j<=c;j++)
        {
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            v[a[i][j]]++;
        }
    cin>>m;
    for(t=1;t<=m;t++)
    {
        cin>>k;
        cout<<v[k]<<'\n';
    }
    return 0;
}

