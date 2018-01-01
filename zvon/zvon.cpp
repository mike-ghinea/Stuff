#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream cin("zvon.in");
ofstream cout("zvon.out");
int a,b,i,t,T,bst[100001],n;
vector <int> arb[100001];
int cmp(int a,int b)
{
    return bst[a]>bst[b];
}
void dfs(int nod)
{
    for(int i=0;i<(int)arb[nod].size();i++)
        dfs(arb[nod][i]);
    std::sort(arb[nod].begin(),arb[nod].end(),cmp);
    for(int i=0;i<(int)arb[nod].size();i++)
        bst[nod]=max(bst[nod],bst[arb[nod][i]]+i+1);
}
int main()
{
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            bst[i]=0;
            arb[i].clear();
        }
        for(i=1;i<n;i++)
        {
            cin>>a>>b;
            arb[a].push_back(b);
        }
        dfs(1);
        cout<<bst[1]<<"\n";
    }
}
