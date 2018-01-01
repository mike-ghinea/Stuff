#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

#define Ndim 100005
#define pb push_back
using namespace std;
ifstream fin("gminmax.in");
ofstream fout("gminmax.out");
int N,M,nrnod,gminmax,grad[Ndim],H[Ndim],Hdim,HPOZ[Ndim];
bool VIZ[Ndim];
vector <int> G[Ndim];
void heap_up(int k)
{
    while(k/2 && grad[H[k]]<grad[H[k/2]])
    {
        swap(HPOZ[H[k]],HPOZ[H[k/2]]);
        swap(H[k],H[k/2]);
        k/=2;
    }
}
void heap_down(int k)
{
    int poz;
    while(k*2<=Hdim)
    {
        poz=k*2;
        if(poz+1 <=Hdim && grad[H[poz]] > grad[H[poz+1]])
            poz++;
        if(grad[H[k]]>grad[H[poz]])
        {
            swap(H[k],H[poz]);
            swap(HPOZ[H[k]],HPOZ[H[poz]]);
            k=poz;
        }
        else
            break;
    }
}
void heap_insert(int nod)
{
    H[++Hdim]=nod;
    HPOZ[nod]=Hdim;
    heap_up(Hdim);
}
int heap_extract()
{
    int x=H[1];
    HPOZ[H[1]]=0;
    H[1]=H[Hdim];
    HPOZ[H[Hdim]]=1;
    heap_down(1);
    Hdim--;
    return x;
}
void read()
{
    int a,b;
    fin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        fin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(int i=1;i<=N;i++)
    {
        grad[i]=G[i].size();
        heap_insert(i);
    }
}

void solve()
{
    int i,x,nod;
    gminmax=grad[H[1]];
    nrnod=N;
    for(i=1;i<N;i++)
    {
        nod=heap_extract();
        VIZ[nod]=1;
        for(size_t j=0;j<G[nod].size();j++)
        {
            x=G[nod][j];
            if(!VIZ[x])
            {
                grad[x]--;
                heap_up(HPOZ[x]);
            }
        }
        if(grad[H[1]]>gminmax)
        {
            gminmax=grad[H[1]];
            nrnod=N-i;
        }
    }
}
void print()
{
    fout<<gminmax<<' '<<nrnod;
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
