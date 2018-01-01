#include <fstream>
#include <string.h>
#include <algorithm>
#include <limits.h>

#define INF INT_MAX
#define Ndim 100005
using namespace std;
ifstream fin("secvmax.in");
ofstream fout("secvmax.out");
int V[Ndim],vf,N,M,SOL[Ndim],BST[Ndim];
struct strct{int nr, val;}STV[Ndim],A[Ndim];
int cmp(strct a,strct b)
{
    return a.val<b.val;
}
int binsrch(int x)
{
    int st=1,dr=N,mid;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(A[mid].val<=x)
            st=mid+1;
        else
            dr=mid-1;
    }
    return A[st-1].nr;
}
void read()
{
    int i;
    fin>>N>>M;
    for(i=1;i<=N;i++)
    {
        fin>>V[i];
        A[i].val=V[i];
        A[i].nr=i;
    }
}
void solve()
{
    int i,nr;
    sort(A+1,A+N+1,cmp);
    STV[0].val=INF;
    vf=0;
    for(i=1;i<=N;i++)
    {
        nr=0;
        while(V[i]>=STV[vf].val)
        {
            nr+=(1+STV[vf].nr);
            vf--;
        }
        STV[++vf].val=V[i];
        STV[vf].nr=nr;
        BST[i]+=nr;
    }
    STV[0].val=INF;
    vf=0;
    for(i=N;i>=1;i--)
    {
        nr=0;
        while(V[i]>=STV[vf].val)
        {
            nr+=(1+STV[vf].nr);
            vf--;
        }
        STV[++vf].val=V[i];
        STV[vf].nr=nr;
        BST[i]+=(nr+1);
    }
    for(i=1;i<=N;i++)
    {
        SOL[A[i].nr]=max(SOL[A[i-1].nr],BST[A[i].nr]);
    }
}
void print()
{
    int i,x;
    for(i=1;i<=M;i++)
    {
        fin>>x;
        fout<<SOL[binsrch(x)]<<'\n';
    }

}
int main()
{
    read();
    solve();
    print();
    return 0;
}
