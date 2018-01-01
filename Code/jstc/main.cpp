#include <fstream>
#include <string.h>

#define Sdim 10000006
#define Idim 1000005
using namespace std;
ifstream fin("jstc.in");
ofstream fout("jstc.out");
int DIS[Idim],STV[Idim],vf,N,NRI,A,X,B;
long long sol;
char S[Sdim];
int root(int x)
{
    while(DIS[x]>0)
        x=DIS[x];
    if(x<=NRI)
        return x;
    return -1;
}
void read()
{
    fin>>A>>B;
    fin>>(S+1);
    N=strlen(S+1);
}
void solve()
{
    int i;
    memset(DIS,-1,sizeof(DIS));
    for(i=1;i<=N;i++)
    {
        if(S[i]=='I')
        {
            NRI++;
            STV[++vf]=NRI;
            continue;
        }
        if(S[i]=='E')
        {
            DIS[NRI+1]+=DIS[STV[vf]];
            DIS[STV[vf]]=NRI+1;
            vf--;
            continue;
        }
        X=(1ll*A*X+B)%NRI+1;
        sol+=root(X);
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
