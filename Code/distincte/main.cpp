#include <fstream>
#include <algorithm>

#define Ndim 100011
#define zeros(x) (x&(-x))
#define MOD 666013
using namespace std;
ifstream fin("distincte.in");
ofstream fout("distincte.out");
int V[Ndim],last[Ndim],AIB[Ndim],N,K,M,SOL[Ndim];
struct strct{int st,dr,poz;}Qe[Ndim];
bool cmp(strct a,strct b)
{
    return a.dr<b.dr;
}
void update_aib(int poz,int val)
{
    if(poz==0)
        return;
    for(int i=poz;i<=N;i+=zeros(i))
    {
        AIB[i]=(AIB[i]+val)%MOD;
        if(AIB[i]<0)
            AIB[i]+=MOD;
    }
}
int query(int poz)
{
    int nr=0;
    for(int i=poz;i>=1;i-=zeros(i))
    {
        nr+=AIB[i];
        if(nr>=MOD)
            nr-=MOD;
    }
    return nr;
}
void read()
{
    int i;
    fin>>N>>K>>M;
    for(i=1;i<=N;i++)
    {
        fin>>V[i];
    }
    for(i=1;i<=M;i++)
    {
        fin>>Qe[i].st>>Qe[i].dr;
        Qe[i].poz=i;
    }
}
void solve()
{
    int i,j=1;
    sort(Qe+1,Qe+M+1,cmp);
    for(i=1;i<=M;i++)
    {
        while(j<=Qe[i].dr)
        {
            update_aib(last[V[j]],-V[j]);
            update_aib(j,V[j]);
            last[V[j]]=j;
            j++;
        }
        SOL[Qe[i].poz]=(query(Qe[i].dr)-query(Qe[i].st-1)+MOD)%MOD;
    }
}
void print()
{
    for(int i=1;i<=M;i++)
    {
        fout<<SOL[i]<<'\n';
    }
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
