#include <fstream>

#define Tdim 5000003
using namespace std;
ifstream fin("feast.in");
ofstream fout("feast.out");
int Q[Tdim],sol,T,A,B;
bool VIZ[Tdim],VAL[Tdim];
void read()
{
    fin>>T>>A>>B;
}
void solve()
{
    int p=1,u=2;
    VIZ[A]=VIZ[B]=1;
    Q[1]=A;Q[2]=B;VAL[A]=VAL[B]=1;
    sol=max(A,B);
    while(p<=u)
    {
        if(VAL[Q[p]]==1)
        {
            if(Q[p]/2+A<=T&&VIZ[Q[p]/2+A]==0)
            {
                Q[++u]=Q[p]/2+A;
                VAL[Q[u]]=0;
                VIZ[Q[u]]=1;
                sol=max(sol,Q[u]);
            }
            if(Q[p]/2+B<=T&&VIZ[Q[p]/2+B]==0)
            {
                Q[++u]=Q[p]/2+B;
                VAL[Q[u]]=0;
                VIZ[Q[u]]=1;
                sol=max(sol,Q[u]);
            }
        }
        if(Q[p]+A<=T&&VIZ[Q[p]+A]==0)
        {
            Q[++u]=Q[p]+A;
            VAL[Q[u]]=VAL[Q[p]];
            VIZ[Q[u]]=1;
            sol=max(sol,Q[u]);
        }
        if(Q[p]+B<=T&&VIZ[Q[p]+B]==0)
        {
            Q[++u]=Q[p]+B;
            VAL[Q[u]]=VAL[Q[p]];
            VIZ[Q[u]]=1;
            sol=max(sol,Q[u]);
        }
        p++;
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
