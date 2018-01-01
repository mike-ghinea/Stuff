#include <fstream>

#define Ndim 50003
using namespace std;
ifstream fin("highcard.in");
ofstream fout("highcard.out");
int N,sol,V[2*Ndim];
void read()
{
    int x;
    fin>>N;
    for(int i=1;i<=N;i++)
    {
        fin>>x;
        V[x]=1;
    }
}
void solve()
{
    int i,nrep=0;
    for(i=1;i<=2*N;i++)
        V[i]+=V[i-1];
    for(i=1;i<=2*N;i++)
    {
        if(V[i]==V[i-1])
        {
            if(V[i]-nrep>0)
            {
                sol++;
                nrep++;
            }
        }
    }
}
void print()
{
    fout<<sol;
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
