#include <fstream>
#include <vector>

#define Ndim 10010
#define Mdim 30010
#define pb push_back
using namespace std;
ifstream fin("drumuri.in");
ofstream fout("drumuri.out");
int sol[3][Mdim/2],nrsol,PAR[Ndim],nrm[Ndim],n,m,a,b;
bool viz[Ndim];
vector <int> G[Ndim];
void DFS(int x)
{
   viz[x]=1;
   for(size_t i=0;i<G[x].size();i++)
   {
      if(viz[G[x][i]]==0)
      {
         PAR[G[x][i]]=x;
         DFS(G[x][i]);
      }
   }
   if((nrm[x]&1)==0)
   {
      for(size_t i=0;i<G[x].size();i++)
      {
          int nod1 = G[x][i];
          int nod2 = G[x][i+1];
         sol[0][++nrsol]=nod1;
         sol[1][nrsol]=x;
         sol[2][nrsol]=nod2;
         for(size_t j=0;j<G[nod1].size();j++)
         {
            if(G[nod1][j]==x)
            {
               G[nod1].erase(G[nod1].begin()+j);
               break;
            }
         }
         nrm[nod1]--;
         i++;
         nod2=G[x][i];
         for(size_t j=0;j<G[nod2].size();j++)
         {
            if(G[nod2][j]==x)
            {
               G[nod2].erase(G[nod2].begin()+j);
               break;
            }
         }

         nrm[nod2]--;
      }
      nrm[x]=0;
      G[x].clear();
   }
   else
   {
        nrm[x]=1;
        for(size_t i=0;i<G[x].size();i++)
        {
            if(G[x][i]!=PAR[x])
            {
                sol[0][++nrsol]=G[x][i];
                sol[1][nrsol]=x;
                for(size_t j=0;j<G[G[x][i]].size();j++)
                {
                    if(G[G[x][i]][j]==x)
                    {
                        G[G[x][i]].erase(G[G[x][i]].begin()+j);
                        break;
                    }
                }
                nrm[G[x][i]]--;
                if(G[x][i+1]==PAR[x])
                {
                   G[x].erase(G[x].begin()+i,G[x].begin()+i+2);
                   i++;
                   G[x].pb(PAR[x]);
                }
                else
                {
                   G[x].erase(G[x].begin()+i,G[x].begin()+i+1);
                }
                i++;
                nrm[G[x][i]]--;
                sol[2][nrsol]=G[x][i];
                for(size_t j=0;j<G[G[x][i]].size();j++)
                {
                    if(G[G[x][i]][j]==x)
                    {
                       G[G[x][i]].erase(G[G[x][i]].begin()+j);
                       break;
                    }
                }
            }
        }
    }
}
int main()
{
   fin>>n>>m;
   for(int i=1;i<=m;i++)
   {
      fin>>a>>b;
      G[a].pb(b);
      G[b].pb(a);
   }
   if(m%2==1)
   {
      fout<<0;
      return 0;
   }
   for(int i=1;i<=n;i++)
      nrm[i]=G[i].size();
   DFS(1);
   fout<<1<<'\n';
   for(int i=1;i<=nrsol;i++)
        fout<<sol[0][i]<<' '<<sol[1][i]<<' '<<sol[2][i]<<'\n';
    return 0;
}
