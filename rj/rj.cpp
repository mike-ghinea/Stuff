#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("rj.in");
ofstream cout("rj.out");
char ch[1000];
int a[103][103],b[103][103],q[2][10202],m,n,i,j,l,c,p,u,xr,xj,yr,yj,Min=10001,x,y;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,-1,-1,1,-1,0,1};
int main()
{
    cin>>n>>m;
    cin.get();
    for(i=1;i<=n;i++){
        cin.getline(ch,1000);
        for(j=0;j<m;j++)
        {

            switch(ch[j]){
                case 'R':a[i][j+1]=1;xr=i;yr=j+1;
                break;
                case 'J':a[i][j+1]=1;xj=i;yj=j+1;
                break;
                case ' ':a[i][j+1]=0;
                break;
                case 'X':a[i][j+1]=-1;
                break;
            }
        }
    }
    for(i=0;i<=n+1;i++)
        a[i][m+1]=a[i][0]=-1;
    for(i=0;i<=m+1;i++)
        a[0][i]=a[n+1][i]=-1;
    memcpy(b,a,sizeof(a));
    p=u=1;
    q[0][p]=xr;
    q[1][p]=yr;
    while(p<=u){
        for(i=0;i<=7;i++)
        {
            l=q[0][p]+dx[i];
            c=q[1][p]+dy[i];
            if(a[l][c]==0)
            {
                u++;
                q[0][u]=l;
                q[1][u]=c;
                a[l][c]=a[q[0][p]][q[1][p]]+1;
            }
        }
        p++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
        }
    memset(q,0,sizeof(q));
    p=u=1;
    q[0][p]=xj;
    q[1][p]=yj;
    while(p<=u){
        for(i=0;i<=7;i++)
        {
            l=q[0][p]+dx[i];
            c=q[1][p]+dy[i];
            if(b[l][c]==0)
            {
                u++;
                q[0][u]=l;
                q[1][u]=c;
                b[l][c]=b[q[0][p]][q[1][p]]+1;
            }
        }
        p++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            cout<<b[i][j]<<" ";
        cout<<'\n';
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==b[i][j]&&a[i][j]>1)
            {
                if(a[i][j]<Min){
                    Min=a[i][j];
                    x=i;y=j;
                }
            }
        }
    cout<<Min<<" "<<x<<" "<<y;
}

