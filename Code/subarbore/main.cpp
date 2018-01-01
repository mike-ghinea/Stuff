#include <fstream>
#include <algorithm>

#define Ndim 41
#define Mdim 40*20+10
#define Tdim 8
using namespace std;
ifstream fin("subarbore.in");
ofstream fout("subarbore.out");
int N,M,t,sol=2000000000,C[Ndim][Ndim],T[Tdim],DISJ[Ndim],nrm,x[Ndim],NODES[Ndim],nrnod;
bool VIZ[Ndim];
struct strct{int x,y;}V[Mdim];
inline int cmp(const strct &a,const strct &b)
{
    return C[a.x][a.y]<C[b.x][b.y];
}
void read()
{
    fin>>N>>M;
    int i,a,b,c;
    for(i=1;i<=M;i++)
    {
        fin>>a>>b>>c;
        C[a][b]=C[b][a]=c;
    }
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>T[i];
        VIZ[T[i]]=1;
        NODES[i]=T[i];
    }
}
void roy_floyd()
{
    int k,i,j;
    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                if(i!=j && C[i][k] && C[k][j] && (C[i][j]>C[i][k]+C[k][j] || !C[i][j]))
                    C[i][j]=C[i][k]+C[k][j];
}
int root(int x)
{
    while(DISJ[x]>0)
        x=DISJ[x];
    return x;
}
int apm_kruskal(int nrn)
{
    int nr=0,i,val=0,j,root1,root2;
    for(i=1;i<=nrnod;i++)
    {
        for(j=i+1;j<=nrnod;j++)
        {
            V[++nr].x=NODES[i];
            V[nr].y=NODES[j];
        }
    }
    for(i=1;i<=N;i++)
        DISJ[i]=-1;
    sort(V+1,V+nr+1,cmp);
    for(i=1;i<=nr;i++)
    {
        root1=root(V[i].x);
        root2=root(V[i].y);
        if(root1!=root2)
        {
            if(DISJ[root1]>DISJ[root2])
                swap(root1,root2);
            DISJ[root1]+=DISJ[root2];
            DISJ[root2]=root1;
            val+=C[V[i].x][V[i].y];
        }
    }
    return val;
}
void subsets(int k)
{
    for(int i=x[k-1]+1;i<=N;i++)
    {
        if(VIZ[i]==0)
        {
            VIZ[i]=1;
            x[k]=i;
            NODES[++nrnod]=i;
            sol=min(sol,apm_kruskal(k));
            if(k<t-2)
                subsets(k+1);
            VIZ[i]=0;
            nrnod--;
        }

    }
}
void solve()
{
    int i,j;
    for(i=1;i<=t;i++)
        for(j=i+1;j<=t;j++)
        {
            V[++nrm].x=T[i];
            V[nrm].y=T[j];
        }
    nrnod=t;
    sort(V+1,V+nrm+1,cmp);
    sol=min(sol,apm_kruskal(0));
    subsets(1);
}
int main()
{
    read();
    roy_floyd();
    solve();
    fout<<sol;
    return 0;
}
