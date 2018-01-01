#include<fstream>
using namespace std;
ifstream cin("royfloyd.in");
ofstream cout("royfloyd.out");
int n,i,j,k,a[101][101];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0 and i!=j)
                a[i][j]=10000;
        }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][j]!=0 and a[i][k]+a[k][j]!=0)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
