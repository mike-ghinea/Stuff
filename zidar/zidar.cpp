#include<fstream>
#include<cstring>
#define inf 0x3f3f3f3f
#define MAXM 55
#define MAXN 25
#define MAXX 65
using namespace std;
ifstream cin("zidar.in");
ofstream cout("zidar.out");
int N,M,X,T,C[MAXM][MAXN],best[MAXM][MAXN][MAXN][MAXX],Z[MAXN][MAXX],i,j,k,sum,x,sol,len,pos;
int main()
{
    cin>>M>>N>>X>>T;
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            {
                cin>>C[i][j];
                C[i][j] += C[i][j-1];
            }
    memset(best,0x3f,sizeof(best));
    memset(Z,0x3f,sizeof(Z));
    int cmin=inf;
    for(j=1;j<=N;j++)
        for(k=j;k<=N and j-k+1<=X;k++)
            {
                best[1][j][k][k-j+1]=C[1][k]-C[1][j-1];
                cmin=min(cmin,best[1][j][k][k-j+1]);
            }
    if(cmin>T)
    {
        cout<<0;
        return 0;
    }
    for(j=1;j<=N;j++)
        for(k=j;k<=N and k-j+1 <=X; k++)
            for(pos = j; pos<=k;pos++)
                Z[pos][k-j+1] = min(Z[pos][k-j+1],best[1][j][k][k-j+1]);
    for(i=2;i<=M and i<=X;i++)
    {
        for(j=1;j<=N;j++)
            for(k=j;k<=N and i+k-j+1<=X;k++)
                for(len=i+k-j;len<=X;len++)
                    for(pos=j;pos<=k;pos++)
                    {
                        int &p=best[i][j][k][len];
                        p=min(p,Z[pos][len-(k-j+1)]+C[i][k]-C[i][j-1]);
                    }
        memset(Z,0x3f,sizeof(Z));
        for(j=1;j<=N;j++)
            for(k=j;k<=N;k++)
                for(pos=j;pos<=k;pos++)
                    for(len=i+k-j;len<=X;len++)
                    {
                        int &z=Z[pos][len];
                        z=min(z,best[i][j][k][len]);
                    }
    }
      for(len=1;len<=X;len++)
    {
        bool OK=0;
        for(i=1;i<=M;i++)
            for(j=1;j<=N;j++)
                for(k=j;k<=N;k++)
                {
                    if(best[i][j][k][len]<=T)
                    {
                        OK=1;
                    }
                }
        if(OK==0)
            break;
    }
    cout<<len-1;
}
