#include<fstream>
using namespace std;
FILE*cin=fopen("ocean14.in","r");
FILE*cout=fopen("ocean14.out","w");
int a[52][52],d[52][52],dd[52][52],n,k,q[2][2700];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int coada(int x,int y)
{
    int p=1,u=1,l,c,i;
    int nr=1;
    q[0][1]=x;
    q[1][1]=y;
    dd[x][y]=1;
    while(p<=u)
    {
        for(i=0;i<4;i++)
        {
            l=q[0][p]+dx[i];
            c=q[1][p]+dy[i];
            if(a[l][c]!=0)
            {
                u++;
                q[0][u]=l;
                q[1][u]=c;
                dd[l][c]=dd[q[0][p]][q[1][p]]+1;
            }
            if(l==n && c==n)
                return dd[x][y];
        }
        p++;
    }
    return dd[x][y];
}
int main()
{
    int i,j;
    fscanf(cin,"%d %d",&n,&k);
    d[n][n]=dd[n][n]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(cin,"%d",&a[i][j]);
    for(i=n;i>=1;i--)
        for(j=n;j>=1;j--)
        {
            if(a[i][j]>0)
                d[i][j]=coada(i,j);
            else
                d[i][j]=-1;
        }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            fprintf(cout,"%d ",d[i][j]);
        fprintf(cout,"\n");
    }


}
