#include <fstream>
#include <vector>
#include <algorithm>

#define dim 100001
using namespace std;
ifstream fin("zvon.in");
ofstream fout("zvon.out");
int test,t,i,a,b,val[dim],n;
vector <int> arb[dim];
bool cmp(int a, int b)
{
    return val[a]>val[b];
}
void DFS(int x)
{
    for(unsigned int i=0;i<arb[x].size();i++)
        DFS(arb[x][i]);
    std::sort(arb[x].begin(),arb[x].end(),cmp);
    for(int i=0;i<arb[x].size();i++)
        val[x]=max(val[x],val[arb[x][i]]+i+1);

}
int main()
{
    fin>>t;
    for(test=1;test<=t;test++)
    {
        fin>>n;
        for(i=1;i<n;i++)
        {
            fin>>a>>b;
            arb[a].push_back(b);
        }
        DFS(1);
        fout<<val[1]<<'\n';
        for(i=1;i<=n;i++)
        {
            val[i]=0;
            arb[i].clear();
        }

    }
    return 0;
}
