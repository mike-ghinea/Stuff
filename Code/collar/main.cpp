#include <fstream>

#define Ndim 99000
using namespace std;
ifstream fin("collar.in");
ofstream fout("collar.out");
int N,l,lg[Ndim],Min[17][Ndim],Max[17][Ndim],V[Ndim],d,j,i,p;
long long sum,sol;
int main()
{
    long long div;
    fin>>N;
    for(i=0;i<N;i++)
    {
        fin>>V[i];
        Min[0][i]=V[i];
        Max[0][i]=V[i];
    }
    l=N+N/2;
    for(i=N;i<N+N/2;i++)
    {
        V[i]=V[i-N];
        Min[0][i]=Min[0][i-N];
        Max[0][i]=Max[0][i-N];
    }
    for(i=2;i<l;i++)
        lg[i]=lg[i/2]+1;
    for(i=1;(1<<i)<l;i++)
        for(j=0;j<l;j++)
        {
            Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
            Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
        }
    for(div=2;div<=N/2;div++)
    {
        if(N%div)
            continue;
        for(p=0;p<div;p++)
        {
            sum=0;
            for(i=p;i<N+p;i+=div)
            {
                j=i+div-1;
                d=lg[j-i];
                sum=sum+max(Max[d][i],Max[d][j-(1<<d)+1])-min(Min[d][i],Min[d][j-(1<<d)+1]);
            }
            sol=max(sol,sum);
        }
    }
    fout<<sol;
    return 0;
}
