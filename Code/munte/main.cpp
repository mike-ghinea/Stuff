#include <fstream>

using namespace std;
ifstream fin("munte.in");
ofstream fout("munte.out");
int N,D,K,P[51],i,n,k,d;
long long nrdr[2][2][51][101],Max;
int main()
{
    fin>>N>>D>>K;
    for(i=1;i<=K;i++)
    {
        fin>>P[i];
    }
    nrdr[0][0][1][1]=1;
    Max=1;
    for(i=2;i<=63;i++)
        Max=Max*2;
    Max--;
    for(d=2;d<=D;d++)
    {
        for(n=1;n<=N;n++)
        {
            nrdr[0][0][n][d]=min(Max,nrdr[0][0][n-1][d-1]+nrdr[0][0][n][d-1]+nrdr[0][0][n+1][d-1]);
            nrdr[1][0][n][d]=min(Max,nrdr[1][0][n-1][d-1]+nrdr[1][0][n][d-1]+nrdr[1][0][n+1][d-1]);
            if(n==N)
            {
                nrdr[1][0][n][d]=min(Max,nrdr[0][0][n-1][d-1]+nrdr[0][0][n][d-1]+nrdr[0][0][n+1][d-1]);
            }
        }
    }
    for(k=1;k<=K;k++)
    {
        for(d=1;d<=D;d++)
        {
            for(n=1;n<=N;n++)
            {
                if(n==P[k])
                {
                    nrdr[0][k%2][n][d]=nrdr[0][1-k%2][n-1][d-1]+nrdr[0][1-k%2][n][d-1]+nrdr[0][1-k%2][n+1][d-1];
                    nrdr[1][k%2][n][d]=nrdr[1][1-k%2][n-1][d-1]+nrdr[1][1-k%2][n][d-1]+nrdr[1][1-k%2][n+1][d-1];
                    if(n==N)
                        nrdr[1][k%2][n][d]=nrdr[0][1-k%2][n-1][d-1]+nrdr[0][1-k%2][n][d-1]+nrdr[0][1-k%2][n+1][d-1];
                }
                else
                {
                    nrdr[0][k%2][n][d]=nrdr[0][k%2][n-1][d-1]+nrdr[0][k%2][n][d-1]+nrdr[0][k%2][n+1][d-1];
                    nrdr[1][k%2][n][d]=nrdr[1][k%2][n-1][d-1]+nrdr[1][k%2][n][d-1]+nrdr[1][k%2][n+1][d-1];
                    if(n==N)
                        nrdr[1][k%2][n][d]=nrdr[0][k%2][n-1][d-1]+nrdr[0][k%2][n][d-1]+nrdr[0][k%2][n+1][d-1];
                }
            }
        }
    }
    fout<<max(1ll,nrdr[1][1-k%2][1][D-1]);
    return 0;
}
