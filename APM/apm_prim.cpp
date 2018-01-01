//PRIM
#include<fstream>
#include<cstring>
#include<vector>
#define MDIM 400001
#define NDIM 200001
using namespace std;
ifstream cin("apm.in");
ofstream cout("apm.out");
int N,M,v[NDIM],H[MDIM],HDIM,poz[NDIM],COST[NDIM];
vector<pair<int,int> >G[NDIM],apm;
void apm_insert(int node)
{
    for(size_t i=0;i<G[node].size();i++)
    {
        pair<int,int> &p=G[node][i];
        int nod=p.first;
        int cost=p.second;
        v[nod]=min(v[nod],cost);
        if(v[nod]==cost)
            COST[nod]=node;
    }
}
void up(int k)
{
    while(k/2 and v[H[k/2]] > v[H[k]])
    {
        swap(poz[H[k/2]],poz[H[k]]);
        swap(H[k/2],H[k]);
        k/=2;
    }
}
void down(int k)
{
    while(2*k<=HDIM)
    {
        int aux=k<<1;
        if(aux+1<=HDIM and v[H[aux]]>v[H[aux+1]])
            aux++;
        if(v[H[k]]>v[H[aux]])
        {
            swap(poz[H[k]],poz[H[aux]]);
            swap(H[k],H[aux]);
            k=aux;
        }
        else
            break;
    }
}
void heap_insert(int node)
{
    H[++HDIM]=node;
    poz[node]=HDIM;
    up(HDIM);
}
int heap_extract()
{
    int x=H[1];
    swap(H[1],H[HDIM]);
    swap(poz[H[1]],poz[H[HDIM]]);
    --HDIM;
    down(1);
    poz[x]=0;
    return x;
}
int main()
{
    cin>>N>>M;
    int i;
    for(i=1;i<=M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));
    }
    memset(v,0x3f,sizeof(v));
    v[1]=0;
    apm_insert(1);
    for(i=2;i<=N;++i)
        heap_insert(i);
    int sol=0;
    for(i=1;i<N;i++)
    {
        int nod=heap_extract();
        apm_insert(nod);
        sol+=v[nod];
        apm.push_back(make_pair(nod,COST[nod]));
        for(size_t j=0;j<G[nod].size();j++)
        {
            int node=G[nod][j].first;
            if(poz[node])
                up(poz[node]);
        }
    }
    cout<<sol<<"\n"<<N-1<<"\n";
    for(i=0;i<N-1;i++)
        cout<<apm[i].first<<" "<<apm[i].second<<"\n";
}
