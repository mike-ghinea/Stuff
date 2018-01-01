#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
#define M 200001
#define foreach(m) for(int i=1;i<=m;i++)
#define N "\n"
using namespace std;
ifstream cin("apm.in");
ofstream cout("apm.out");
struct a{int x,y,c;}v[2*M];
int m,n,G[M],k,poz[2*M],sol;
vector <int> vec;
bool cmp(int x,int y)
{
    return v[x].c<v[y].c;
}
int pmd(int i)
{
    if(G[i]<0)
        return i;
    G[i]=pmd(G[i]);
    return G[i];
}
int main()
{
    cin>>n>>m;
    foreach(m)
    {
        cin>>v[i].x>>v[i].y>>v[i].c;
        poz[i]=i;
    }
    memset(G,-1,sizeof(G));
    sort(poz+1,poz+m+1,cmp);
    foreach(m)
    {
        k=poz[i];
        if(pmd(v[k].x) != pmd(v[k].y))
        {
            sol+=v[k].c;
            G[pmd(v[k].x)]=pmd(v[k].y);
            vec.push_back(k);
        }
    }
    cout<<sol<<N<<n-1<<N;
    foreach(n-1)
        cout<<v[vec[i-1]].x<<" "<<v[vec[i-1]].y<<N;
    return 0;
}
