#include <fstream>

using namespace std;
ifstream fin("rmq.in");
ofstream fout("rmq.out");
int n,lg[100001],m,a,b,rmq[20][100000],i,j,p;
int main()
{
    fin>>n>>m>>rmq[0][1];
    for(i=2;i<=n;i++)
    {
        fin>>rmq[0][i];
        lg[i]=lg[i/2]+1;
    }
    for(i=1;(1<<i)<=n;i++)
        for(j=1;j<=n;j++)
            rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
    for(i=1;i<=m;i++)
    {
        fin>>a>>b;
        p=lg[b-a+1];
        fout<<min(rmq[p][a],rmq[p][b-(1<<p)+1]);
    }
    return 0;
}
