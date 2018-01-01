#include <fstream>

#define Ndim 300004
#define MOD 666013
using namespace std;
ifstream fin("minesweeper2.in");
ofstream fout("minesweeper2.out");
int N,V[Ndim],D[2][Ndim][4],sol;
void read()
{
    fin>>N;
    for(int i=1;i<=N;i++)
        fin>>V[i];
}
void prep()
{
    if(V[1]==0)
        D[0][1][0]=1;
    if(V[1]==1||V[1]==-1)
    {
        D[0][1][0]=1;
        D[1][1][1]=1;
    }
    if(V[1]==2)
        D[1][1][1]=1;
}
void dinamic_solve()
{
    int i;
    prep();
    for(i=2;i<=N;i++)
    {
        if(V[i-1]!=-1)
        {
            if(V[i]==-1)
            {
                D[1][i][1]=D[0][i-1][V[i-1]-1];
                D[1][i][2]=D[1][i-1][V[i-1]-1];
                D[0][i][0]=D[0][i-1][V[i-1]];
                D[0][i][1]=D[1][i-1][V[i-1]];
            }
            else
            {
                if(V[i]==0)
                {
                    D[0][i][0]=D[0][i-1][V[i-1]];
                    continue;
                }
                if(V[i]==1)
                {
                    D[0][i][0]=D[0][i-1][V[i-1]];
                    D[0][i][1]=D[1][i-1][V[i-1]];
                    D[1][i][1]=D[0][i-1][V[i-1]-1];
                    continue;
                }
                if(V[i]==2)
                {
                    D[0][i][1]=D[1][i-1][V[i-1]];
                    D[1][i][1]=D[0][i-1][V[i-1]-1];
                    D[1][i][2]=D[1][i-1][V[i-1]-1];
                    continue;
                }
                D[1][i][2]=D[1][i-1][V[i-1]-1];
            }
        }
        else
        {
            if(V[i]==-1)
            {
                D[0][i][0]=(D[0][i-1][0]+D[0][i-1][1])%MOD;
                D[0][i][1]=(D[1][i-1][1]+D[1][i-1][2])%MOD;
                D[1][i][1]=(D[0][i-1][0]+D[0][i-1][1])%MOD;
                D[1][i][2]=(D[1][i-1][1]+D[1][i-1][2])%MOD;
            }
            else
            {
                if(V[i]==0)
                {
                    D[0][i][0]=(D[0][i-1][0]+D[0][i-1][1])%MOD;
                    continue;
                }
                if(V[i]==1)
                {
                    D[0][i][0]=(D[0][i-1][0]+D[0][i-1][1])%MOD;
                    D[0][i][1]=(D[1][i-1][1]+D[1][i-1][2])%MOD;
                    D[1][i][1]=(D[0][i-1][0]+D[0][i-1][1])%MOD;
                    continue;
                }
                if(V[i]==2)
                {
                    D[0][i][1]=(D[1][i-1][1]+D[1][i-1][2])%MOD;
                    D[1][i][1]=(D[0][i-1][0]+D[0][i-1][1])%MOD;
                    D[1][i][2]=(D[1][i-1][1]+D[1][i-1][2])%MOD;
                    continue;
                }
                D[1][i][2]=(D[1][i-1][1]+D[1][i-1][2])%MOD;
            }
        }
    }
    if(V[N]!=-1)
        sol=(D[0][N][V[N]]+D[1][N][V[N]])%MOD;
    else
    {
        sol=(D[0][N][0]+D[0][N][1]+D[1][N][1]+D[1][N][2])%MOD;
    }
}
void print()
{
    fout<<sol;
}
int main()
{
    read();
    dinamic_solve();
    print();
    return 0;
}
