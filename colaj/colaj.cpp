#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("colaj.in");
ofstream cout("colaj.out");
int xl[103],xc[103],yl[103],yc[103],x[500],y[500],normx[500],normy[500],j=1,st,dr,kx,ky,mij,n,m,p,nr,i,l,c,l1,l2,c1,c2,q[2][2500];
bool a[501][501];
int binx(int k)
{
    st=1;
    dr=kx;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(x[mij]<k)
            st=mij+1;
        else if(x[mij]>k)
            dr=mij-1;
        else
            return mij;
    }
    return mij;
}
int biny(int k)
{
    st=1;
    dr=ky;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(y[mij]<k)
            st=mij+1;
        else if(y[mij]>k)
            dr=mij-1;
        else
            return mij;
    }
    return mij;
}
void coada(int aa,int b)
{
    int x,y;
    int dx[]={-1,0,1,0},p=1,u=1;
    int dy[]={0,1,0,-1};
    q[0][p]=aa;
    q[1][p]=b;
    a[aa][b]=1;
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        for(i=0;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(a[l][c]==0)
            {
                u++;
                q[0][u]=l;
                q[1][u]=c;
                a[l][c]=1;
            }
        }
        p++;
    }
    nr++;
}
int main()
{
    cin>>n>>m>>p;
    for(i=1;i<=n;i++)
    {
        cin>>xl[i]>>yl[i]>>xc[i]>>yc[i];
        x[++j]=xl[i];
        y[j]=yl[i];
        x[++j]=xc[i];
        y[j]=yc[i];
    }
    sort(x+1,x+j+1);
    sort(y+1,y+j+1);
    x[++j]=m;
    y[j]=p;
    kx=1;
    for(i=2;i<=j;i++)
        if(x[i]!=x[i-1])
            x[++kx]=x[i];
    ky=1;
    for(i=2;i<=j;i++)
        if(y[i]!=y[i-1])
            y[++ky]=y[i];
    normx[1]=1;
    for(i=2;i<=kx;i++)
        normx[i]=normx[i-1]+2;
    normy[1]=1;
    for(i=2;i<=ky;i++)
        normy[i]=normy[i-1]+2;

    for(i=1;i<=n;i++)
    {
        l1=xl[i];
        c1=yl[i];
        l2=xc[i];
        c2=yc[i];
        l1=normx[binx(l1)];
        l2=normx[binx(l2)];
        c1=normy[biny(c1)];
        c2=normy[biny(c2)];
        for(l=l1;l<=l2;l++)
            for(c=c1;c<=c2;c++)
                a[l][c]=1;
    }
    for(i=0;i<=normx[kx];i++)
        a[i][0]=a[i][normy[ky]]=1;
    for(i=0;i<=normy[ky];i++)
        a[0][i]=a[normx[kx]][i]=1;
    for(i=1;i<=normx[kx]-1;i++)
       {
           for(j=1;j<=normy[ky]-1;j++)
            cout<<a[i][j]<<" ";
            cout<<"\n";
       }

            //if(a[i][j]==0)
            //coada(i,j);
    cout<<nr;
    return 0;
}
