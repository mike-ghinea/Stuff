#include <fstream>
#include <vector>
#include <string.h>
#define nMax 17001
#include <algorithm>
using namespace std;
ifstream fin("razboi.in");
ofstream fout("razboi.out");
vector<pair<int, int> > G[nMax];
int sol[nMax], t, k, k1, h, n, i, a, b, c;
long long dist[nMax], Min, timp, dstap, dlat;
struct cub
{
    long long l1;
    long long l2;
}v[nMax];
void DFS(int node, int tata)
{
    if(G[node].size()==1)
        v[node].l1=dist[node];
    for(vector<pair<int, int> >::iterator it=G[node].begin();it!=G[node].end();it++)
        if(it->first!=tata)
        {
            dist[it->first]=dist[node]+it->second;
            DFS(it->first, node);
            if(v[it->first].l1>v[node].l1)
            {
                v[node].l2=v[node].l1;
                v[node].l1=v[it->first].l1;
            }
            else
                if(v[it->first].l1>v[node].l2)
                    v[node].l2=v[it->first].l1;
        }
}
void Solve(int node, int stapan, int tata)
{
    dstap=v[stapan].l1;
    if(v[node].l1==dstap)
        dstap=v[stapan].l2;
    dlat=v[tata].l1;
    if(v[node].l1==dlat)
        dlat=v[tata].l2;
    dlat-=dist[tata];
    if(dist[node]+dstap<dist[node]-dist[tata]+dlat)
    {
        stapan=tata;
        timp=dist[node]-dist[tata]+dlat;
    }
    else
        timp=dstap+dist[node];
    timp=max(timp, v[node].l1-dist[node]);
    if(timp<=Min)
    {
        if(timp<Min)
        {
            Min=timp;
            h=0;
        }
        sol[++h]=node;
    }
    for(vector<pair<int, int> >::iterator it=G[node].begin();it!=G[node].end();it++)
        if(it->first!=tata)
            Solve(it->first, stapan, node);
}
int main()
{
    fin>>t;
    for(k=1;k<=t;k++)
    {
        fin>>n;
        fout<<"Testul nr #"<<k<<'\n';
        if(n==1)
            continue;
        for(i=1;i<n;i++)
        {
            fin>>a>>b>>c;
            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, c));
        }
        for(vector<pair<int, int> >::iterator tit=G[1].begin();tit!=G[1].end();tit++)
        {
            dist[tit->first]+=tit->second;
            DFS(tit->first, 1);
            if(v[tit->first].l1>v[1].l1)
            {
                v[1].l2=v[1].l1;
                v[1].l1=v[tit->first].l1;
            }
            else
                if(v[tit->first].l1>v[1].l2)
                    v[1].l2=v[tit->first].l1;
        }
        Min=v[1].l1;
        h=0;
        sol[++h]=1;
        for(vector<pair<int, int> >::iterator tit=G[1].begin();tit!=G[1].end();tit++)
            Solve(tit->first, 1, 1);
        sort(sol+1, sol+h+1);
        for(k1=1;k1<=h;k1++)
            fout<<sol[k1]<<'\n';
        memset(v, 0, sizeof(v));
        memset(G, 0, sizeof(G));
        memset(dist, 0, sizeof(dist));
    }
    return 0;
}
