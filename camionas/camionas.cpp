#include<fstream>
#include<vector>
#define inf 1000000
#define N 50010
using namespace std;
ifstream cin("camionas.in");
ofstream cout("camionas.out");
int n,m,c,g,x,y,poz[N],drum[N],dim,nod,H[N],i,j;
vector <pair <int,int> > G[N];
void up(int nod)
{
    while(nod/2>0 and drum[H[nod/2]]>drum[H[nod]])
    {
        swap(H[nod],H[nod/2]);
        swap(poz[H[nod]],poz[H[nod/2]]);
        nod/=2;
    }
}
void down()
{
    int nod=1;
    while(nod*2<=dim)
    {
        int aux=nod*2;
        if(aux+1<=dim and drum[H[aux+1]]<drum[H[aux]])
            aux++;
        if(drum[H[aux]]<drum[H[nod]])
        {
            swap(H[aux],H[nod]);
            swap(poz[H[aux]],poz[H[nod]]);
            nod=aux;
        }
        else
            break;
    }
}
void dijkstra()
{
    H[++dim]=1;
    poz[1]=1;
    drum[1]=0;
    for(i=2;i<=n;i++)
        drum[i]=inf;
    for(i=1;i<=n;i++)
    {
        nod=H[1];
        H[1]=H[dim];
        poz[H[1]]=1;
        dim--;
        down();
        for(j=0;j<(int)G[nod].size();j++)
        {
            x=G[nod][j].first;
            c=G[nod][j].second;
            if(drum[x]>drum[nod]+c)
            {
                drum[x]=drum[nod]+c;
                if(!poz[x])
                {
                    H[++dim]=x;
                    poz[x]=dim;
                    up(dim);
                }
                else
                    up(poz[x]);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>g;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        if(c<g)
            c=1;
        else
            c=0;
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));
    }
    dijkstra();
    cout<<drum[n];
    return 0;
}
