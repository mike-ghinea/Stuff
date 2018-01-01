#include <fstream>

#define Ndim 505
using namespace std;
ifstream fin("plantatie.in");
ofstream fout("plantatie.out");
int N,M,lg[Ndim],RMQ[10][Ndim][Ndim];
void read()
{
    int i,j;
    fin>>N>>M;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            fin>>RMQ[0][i][j];
}
void rmq()
{
    int i,j,k;
    for(i=2;i<=N;i++)
        lg[i]=lg[i/2]+1;
    for(k=1;(1<<k)<=N;k++)
        for(i=1;i+(1<<k)-1<=N;i++)
            for(j=1;j+(1<<k)-1<=N;j++)
                RMQ[k][i][j]=max(max(max(RMQ[k-1][i][j] , RMQ[k-1][i+(1<<(k-1))][j]) ,
                                RMQ[k-1][i][j+(1<<(k-1))]) , RMQ[k-1][i+(1<<(k-1))][j+(1<<(k-1))]);
}
void solve()
{
    int i,x,y,k,p;
    for(i=1;i<=M;i++)
    {
        fin>>x>>y>>k;
        p=lg[k];
        fout<<max(max(max(RMQ[p][x][y] , RMQ[p][x+k-(1<<p)][y]) ,
                RMQ[p][x][y+k-(1<<p)]) , RMQ[p][x+k-(1<<p)][y+k-(1<<p)])<<'\n';
    }
}
int main()
{
    read();
    rmq();
    solve();
    return 0;
}
