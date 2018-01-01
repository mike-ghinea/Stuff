#include <fstream>
#include <string.h>

#define DIM 105
using namespace std;
ifstream fin ("poarta.in");
ofstream fout ("poarta.out");
int N,M,K,L1,C1,L2,C2,a[DIM][DIM],q[2][DIM*DIM],dist1,dist2,nrdrum,nrdrumnoport;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
bool viz[DIM][DIM];
void read ()
{
    int LP,CP,i;

    fin>>N>>M>>K;
    fin>>L1>>C1>>L2>>C2;

    for(i=1;i<=K;i++)
    {
        fin>>LP>>CP;
        q[0][i]=LP;
        q[1][i]=CP;
        a[LP][CP]=0;
    }
}

void vizare()
{
    int i;
    for(i=0; i<=N+1; i++)
    {
        viz[i][0]=1;
        viz[i][M+1]=1;
    }
    for(i=0; i<=M+1; i++)
    {
        viz[0][i]=1;
        viz[N+1][i]=1;
    }
}
void bordare ()
{
    int i;
    for(i=0; i<=N+1; i++)
    {
        a[i][0]=-1;
        a[i][M+1]=-1;
    }
    for(i=0; i<=M+1; i++)
    {
        a[0][i]=-1;
        a[N+1][i]=-1;
    }
}
void Fill ()
{
    int p,u,x,y,l,c,i;
    p=1;
    u=K;
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        viz[x][y]=1;
        for(i=0;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];

            if(viz[l][c]==0)
            {
                q[0][++u]=l;
                q[1][u]=c;
                a[l][c]=a[x][y]+1;
                viz[l][c]=1;
            }
        }
        p++;
    }

    dist1=a[L1][C1]+a[L2][C2]+1;

}
void nrport()
{
    int i,x1,x2,l,c,nrdrum1=0,nrdrum2=0,nr=0;
    bordare();
    nr=a[L1][C1];
    x1=L1;
    x2=C1;
    for(i=0;i<4;i++)
    {
        l=x1+dx[i];
        c=x2+dy[i];
        if(a[l][c]<nr && a[l][c]!=-1)
            nrdrum1++;

    }


    nr=a[L2][C2];
    x1=L2;
    x2=C2;
    for(i=0;i<4;i++)
    {
        l=x1+dx[i];
        c=x2+dy[i];
        if(a[l][c]<nr && a[l][c]!=-1)
            nrdrum2++;
    }



    nrdrum=nrdrum1*nrdrum2;
}
void distanta ()
{
    int p,u,l,c,x,y,i;
    memset(viz,0,sizeof(viz));
    memset(a,0,sizeof(a));
    vizare();
    p=u=1;
    q[0][p]=L1;
    q[1][p]=C1;
    viz[L1][C1]=1;
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        for(i=1;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(viz[l][c]==0)
            {
                q[0][++u]=l;
                q[1][u]=c;
                viz[l][c]=1;
                a[l][c]=a[x][y]+1;
            }
        }
        p++;
    }

    dist2=a[L2][C2];
}
void nrnoport()
{
    int p=0,u=0,i=0,l=0,c=0,x=0,y=0;
    memset(viz,0,sizeof(viz));
    memset(a,0,sizeof(a));
    vizare();
    p=1;
    u=K;
    for(i=1;i<=u;i++)
    {
        l=q[0][i];
        c=q[1][i];
        viz[l][c]=1;
    }

    p=1;
    u=1;
    q[0][p]=L1;
    q[1][p]=C1;
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        for(i=0;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(viz[l][c]==0)
            {
                viz[l][c]=1;
                q[0][++u]=l;
                q[1][u]=c;
                a[l][c]+=a[x][y];
            }
        }
        p++;
    }
    nrdrumnoport=a[L2][C2];
}
int main()
{
    int i;
    read();

    vizare();
    Fill();
    nrport();

    nrnoport();
    distanta();



    if(dist1<dist2)
    {
        fout<<dist1<<'\n';
        fout<<nrdrum;
    }
    if(dist1>dist2)
    {
        fout<<dist2;
        fout<<nrdrumnoport;

    }




    return 0;
}
