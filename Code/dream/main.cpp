#include <fstream>
#include <string.h>

#define INF 1000*1000+100
#define Ndim 1004
using namespace std;
ifstream fin("dream.in");
ofstream fout("dream.out");
int D[Ndim][Ndim],Q[2][Ndim*Ndim],N,M;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char A[Ndim][Ndim];
bool m[Ndim][Ndim];
void read()
{
    fin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            fin>>A[i][j],D[i][j]=INF;
}
void solve()
{
    int p=1,u=1,i,l,c,x,y,val;
    Q[0][p]=Q[1][p]=1;
    D[1][1]=0;
    while(p<=u)
    {
        x=Q[0][p];
        y=Q[1][p];
        for(i=0;i<4;i++)
        {
            l=x+dx[i];
            c=y+dy[i];
            if(A[l][c]!=0&&A[l][c]!='0')
            {
                if(A[l][c]=='1'&&(D[l][c]>D[x][y]+1||(m[x][y]==1&&m[l][c]==0)))
                {
                    Q[0][++u]=l;
                    Q[1][u]=c;
                    m[l][c]=m[x][y];
                    D[l][c]=D[x][y]+1;
                    continue;
                }
                if(A[l][c]=='2'&&D[l][c]>D[x][y]+1)
                {
                    Q[0][++u]=l;
                    Q[1][u]=c;
                    m[l][c]=1;
                    D[l][c]=D[x][y]+1;
                    continue;
                }
                if(A[l][c]=='3'&&m[x][y]==1&&D[l][c]>D[x][y]+1)
                {
                    Q[0][++u]=l;
                    Q[1][u]=c;
                    m[l][c]=1;
                    D[l][c]=D[x][y]+1;
                    continue;
                }
                if(A[l][c]=='4')
                {
                    l+=dx[i];
                    c+=dy[i];
                    val=D[x][y]+1;
                    while(A[l][c]=='4')
                    {
                        l+=dx[i];
                        c+=dy[i];
                        val++;
                    }
                    if((A[l][c]=='0'||A[l][c]=='3'||A[l][c]==0)&&D[l-dx[i]][c-dy[i]]>val)
                    {
                        l-=dx[i];
                        c-=dy[i];
                        Q[0][++u]=l;
                        Q[1][u]=c;
                        m[l][c]=0;
                        D[l][c]=val;
                        continue;
                    }
                    if(A[l][c]=='1'&&D[l][c]>val+1)
                    {
                        Q[0][++u]=l;
                        Q[1][u]=c;
                        m[l][c]=0;
                        D[l][c]=val+1;
                    }
                    if(A[l][c]=='2'&&D[l][c]>val+1)
                    {
                        Q[0][++u]=l;
                        Q[1][u]=c;
                        m[l][c]=1;
                        D[l][c]=val+1;
                    }
                }
            }
        }
        p++;
    }
}
void print()
{
    if(D[N][M]!=INF)
        fout<<D[N][M];
    else
        fout<<-1;
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
