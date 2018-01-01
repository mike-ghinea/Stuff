#include <fstream>

using namespace std;
ifstream fin("speeding.in");
ofstream fout("speeding.out");
int V[102],S[102],N,M;
void read()
{
    int a,b,last=1,i,j,dist=0;
    fin>>N>>M;
    for(i=1;i<=N;i++)
    {
        fin>>a>>b;
        dist+=a;
        for(j=last;j<=dist;j++)
        {
            V[j]=b;
        }
        last=dist+1;
    }
    last=1;
    dist=0;
    for(i=1;i<=M;i++)
    {
        fin>>a>>b;
        dist+=a;
        for(j=last;j<=dist;j++)
        {
            S[j]=b;
        }
        last=dist+1;
    }
}
void solve()
{
    int sol=0,i;
    for(i=1;i<=100;i++)
    {
        sol=max(sol,S[i]-V[i]);
    }
    fout<<sol;
}
int main()
{
    read();
    solve();
    return 0;
}
