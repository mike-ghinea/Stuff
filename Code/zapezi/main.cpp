#include <fstream>
#include <vector>
#include <string.h>

#define pb push_back
#define mkp make_pair
#define Ndim 10005
#define fi first
#define se second
using namespace std;
ifstream fin("zapezi.in");
ofstream fout("zapezi.out");
int N,Source,BST[2][Ndim][3][3];
vector <pair <int,int> > G[Ndim];
bool VIZ[Ndim];
void read()
{
    int i,a,b,c;
    fin>>N>>Source;
    for(i=1;i<N;i++)
    {
        fin>>a>>b>>c;
        G[a].pb(mkp(b,c));
        G[b].pb(mkp(a,c));
    }
}
void DFS(int nod)
{
    int cost,fiu,nf=0,cur;
    VIZ[nod]=1;
    cur=0;
    for(size_t i=0;i<G[nod].size();i++)
    {
        if(!VIZ[G[nod][i].fi])
        {
            nf++;
            DFS(G[nod][i].fi);
            cost=G[nod][i].se;
            fiu=G[nod][i].fi;
            cur=(cur^1);
            BST[cur][nod][1][0]=min(BST[(cur^1)][nod][1][1]+BST[0][fiu][1][0]+cost,BST[(cur^1)][nod][1][0]+BST[0][fiu][1][1]+2*cost);
            BST[cur][nod][1][1]=BST[(cur^1)][nod][1][1]+BST[0][fiu][1][1]+2*cost;
            BST[cur][nod][2][0]=min(BST[cur^1][nod][1][0]+BST[0][fiu][2][1]+3*cost,min(BST[(cur^1)][nod][1][1]+BST[0][fiu][2][0]+2*cost,min(BST[(cur^1)][nod][2][0]+BST[0][fiu][1][1]+2*cost,min(BST[(cur^1)][nod][2][1]+BST[0][fiu][1][0]+cost,BST[(cur^1)][nod][1][0]+BST[0][fiu][1][0]+cost))));
            BST[cur][nod][2][1]=min(BST[0][fiu][1][1]+2*cost+BST[cur^1][nod][1][0],min(BST[cur^1][nod][2][1]+BST[0][fiu][1][1]+2*cost,BST[0][fiu][2][1]+3*cost+BST[cur^1][nod][1][1]));
        }
    }
    BST[cur^1][nod][1][0]=BST[cur][nod][1][0];
    BST[cur^1][nod][2][0]=BST[cur][nod][2][0];
    BST[cur^1][nod][1][1]=BST[cur][nod][1][1];
    BST[cur^1][nod][2][1]=BST[cur][nod][2][1];
//    if(nf==0)
//        BST[0][nod][1][0]=BST[0][nod][1][1]=BST[1][nod][1][0]=BST[1][nod][1][1]=0;
}
void print()
{
    fout<<min(BST[0][Source][1][0],BST[0][Source][2][0]);
}
int main()
{
    read();
    DFS(Source);
    print();
    return 0;
}
