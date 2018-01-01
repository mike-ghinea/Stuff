#include<fstream>
using namespace std;
ifstream cin("bfs.in");
ofstream cout("bfs.out");
int q[102],a,b,n,m,x,s=1,i,k;
bool ma[102][102],viz[102];
int main()
{
    cin>>n>>m>>x;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        ma[a][b]=ma[b][a]=1;
    }
    q[1]=x;
    cout<<x<<" ";
    viz[x]=1;
    while(s<n)
    {
        for(i=1;i<=n;i++)
        {
            if(ma[x][i]==1 && viz[i]==0)
            {
                cout<<i<<" ";
                viz[i]=1;
                s++;
                q[s]=i;
            }
        }
        k++;
        x=q[k];
    }
    return 0;
}
