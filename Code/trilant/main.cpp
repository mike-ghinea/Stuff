#include <fstream>
#include <vector>
#include <limits.h>
#include<string.h>
#define DIM 100002
#define inf 400000000010ll
using namespace std;
ifstream fin("trilant.in");
ofstream fout("trilant.out");
int n,m,a,b,c,x,y,z,v1,v2,v3,lant,cost,nod,nou,dim[4],poz[4][DIM],H[4][DIM],i,j,f[4][DIM],nr,t[4][DIM],Poz[DIM];
char s[103];
long long d[4][DIM],dmin;
bool viz[DIM];
vector < pair <int,int> > G[DIM];
void up(int lant,int k)
{
    while(k/2)
    {
        if(d[lant][H[lant][k]]<d[lant][H[lant][k/2]])
        {
            swap(H[lant][k],H[lant][k/2]);
            poz[lant][H[lant][k/2]]=k/2;
            poz[lant][H[lant][k]]=k;
            k/=2;
        }
        else
            break;
    }
}
void down(int lant, int dim)
{
    int k=1;
    int po;
    while(2*k<=dim)
    {
        po=2*k;
        if(po+1<=dim&&d[lant][H[lant][po]]>d[lant][H[lant][po+1]])
            po++;
        if(d[lant][H[lant][k]]>d[lant][H[lant][po]])
        {
            swap(H[lant][k],H[lant][po]);
            poz[lant][H[lant][k]]=k;
            poz[lant][H[lant][po]]=po;
            k=po;
        }
        else
            break;
    }
}
void drum(int lant,int nod)
{
    for(int i=0;i<G[nod].size();i++)
    {
        nou = G[nod][i].first;
        cost = G[nod][i].second;
        if(d[lant][nod]==d[lant][nou]+cost&&viz[nou]==0)
        {
            viz[nou]=1;
            f[lant][++f[lant][0]]=nou;
            drum(lant,nou);
        }
    }
}
void dijkstra(int lant)
{

    for(i=1;i<n;i++)
    {
        nod=H[lant][1];
        H[lant][1]=H[lant][dim[lant]];
        poz[lant][H[lant][1]]=1;
        dim[lant]--;
        down(lant,dim[lant]);
        for(j=0;j<G[nod].size();j++)
        {
            nou=G[nod][j].first;
            cost=G[nod][j].second;
            if(d[lant][nou]>d[lant][nod]+cost)
            {
                d[lant][nou]=d[lant][nod]+cost;
                t[lant][nou]=nod;
                if(poz[lant][nou]==0)
                {
                    H[lant][++dim[lant]]=nou;
                    poz[lant][nou]=dim[lant];
                    up(lant,dim[lant]);
                }
                else
                    up(lant,poz[lant][nou]);
            }
        }
    }
}
int main()
{
    fin>>n>>m>>a>>b>>c;
    fin.get();
    for(i=1;i<=m;i++)
    {
        fin.getline(s,100);
        j=x=y=z=nr=0;
        while(s[j]!=0)
        {
            if(s[j]>='0'&&s[j]<='9')
                nr=nr*10+s[j]-'0';
            else
            {
                if(!x)
                {
                    x=nr; nr=0;
                }
                else if(!y)
                {
                    y=nr; nr=0;
                }
            }
            j++;
        }
        z=nr;
        G[x].push_back(make_pair(y,z));
        G[y].push_back(make_pair(x,z));
    }
    H[1][++dim[1]]=a;poz[1][a]=dim[1];
    H[2][++dim[2]]=b;poz[2][b]=dim[2];
    H[3][++dim[3]]=c;poz[3][c]=dim[3];
    for(i=1;i<=3;i++)
        for(j=1;j<=n;j++)
            d[i][j]=inf;
    d[1][a]=0;
    d[2][b]=0;
    d[3][c]=0;
    dijkstra(1);
    dijkstra(2);
    dijkstra(3);
    long long sol=inf;
    for(i=1;i<=n;i++)
    {
        if(d[1][i]!=inf&&d[2][i]!=inf&&d[3][i]!=inf)
            if(sol>d[1][i]+d[2][i]+d[3][i])
            {
                sol=d[1][i]+d[2][i]+d[3][i];
                x=i;
            }

    }
    fout<<sol;
   int nr=0,p=x;

    while(t[1][p]!=0){
        Poz[++nr]=p;

        p=t[1][p];
    }
    Poz[++nr]=a;
    fout<<'\n'<<nr<<" ";
    for(int i=1;i<=nr;i++)
        fout<<Poz[i]<<' ';
    p=x;
    nr=0;

    while(t[2][p]!=0){
        Poz[++nr]=p;
        p=t[2][p];
    }
    Poz[++nr]=b;
    fout<<'\n'<<nr<<" ";
    for(int i=1;i<=nr;i++)
        fout<<Poz[i]<<' ';

    p=x;
    nr=0;

    while(t[3][p]!=0){
        Poz[++nr]=p;
        p=t[3][p];
    }
     Poz[++nr]=c;
    fout<<'\n'<<nr<<" ";
    for(int i=1;i<=nr;i++)
    fout<<Poz[i]<<' ';
    return 0;
}
