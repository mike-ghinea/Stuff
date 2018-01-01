#include <fstream>
#define DIM 102
using namespace std;
ifstream fin ("homm.in");
ofstream fout ("homm.out");
int A[DIM][DIM],N,M,K,sol[DIM][DIM],D[2][DIM][DIM],x1,x2,y1,y2;
void read()
{
    int i,j;
    fin>>N>>M>>K;
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++)
        {
            fin>>A[i][j];
        }
    }
    fin>>x1>>y1>>x2>>y2;
}
int sumvec (int l, int c, int k)
{
    return D[1-k%2][l-1][c]+D[1-k%2][l][c+1]+D[1-k%2][l][c-1]+D[1-k%2][l+1][c];
}
void dinamica ()
{
    int i,j,k;
    D[0][x1][y1]=1;
    sol[x1][y1]=1;
    for(k=1; k<=K; k++)
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(A[i][j]!=0)
                    continue;
                D[k%2][i][j]=sumvec(i,j,k);
                sol[i][j]+=D[k%2][i][j];
            }
        }
    }
}
int main()
{
    read();
    dinamica();
    fout<<sol[x2][y2];
    return 0;
}
