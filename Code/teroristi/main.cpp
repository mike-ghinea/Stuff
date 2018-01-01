#include <fstream>
#include <vector>
#include <string.h>

#define source 26+27*28+5
#define dest 26+27*28+6
#define nrnod 26+27*28+10
#define Ndim 1000010
#define pb push_back
#define INF 2*Ndim
using namespace std;
ifstream fin("teroristi.in");
ofstream fout("teroristi.out");
int N,M,SOL[Ndim],C[nrnod][nrnod],F[nrnod][nrnod],PAR[nrnod],Q[nrnod];
vector <int> POZ[27],B[27][27],G[nrnod];
char S[Ndim];
bool VIZ[nrnod];
int cod(int a,int b)
{
    return (a+1)*26+b;
}
void read()
{
    int i,j;
    char a,b;
    fin>>N>>M;
    fin>>S+1;
    for(i=1;i<=N;i++)
    {
        POZ[S[i]-'a'].pb(i);
    }
    for(i=1;i<=M;i++)
    {
        fin>>a>>b;
        if(a>b)
            swap(a,b);
        B[a-'a'][b-'a'].pb(i);
    }
}
void prep()
{
    int i,j;
    for(i=0;i<26;i++)
    {
        if(POZ[i].size())
        {
            G[source].pb(i);
            G[i].pb(source);
            C[source][i]=POZ[i].size();
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=i;j<26;j++)
        {
            if(B[i][j].size())
            {
                G[cod(i,j)].pb(dest);
                G[dest].pb(cod(i,j));
                if(POZ[i].size())
                {
                    G[i].pb(cod(i,j));
                    G[cod(i,j)].pb(i);
                    C[i][cod(i,j)]=INF;
                }
                if(POZ[j].size())
                {
                    G[j].pb(cod(i,j));
                    G[cod(i,j)].pb(j);
                    C[j][cod(i,j)]=INF;
                }
                C[cod(i,j)][dest]=B[i][j].size();
            }
        }
    }
}
int BFS()
{
    memset(VIZ,0,sizeof(VIZ));
    memset(PAR,-1,sizeof(PAR));
    int nod,fiu,p=1,u=1;
    Q[1]=source;
    VIZ[source]=1;
    while(p<=u)
    {
        nod=Q[p];
        if(nod==dest)
        {
            p++;
            continue;
        }
        for(size_t i=0;i<G[nod].size();i++)
        {
            fiu=G[nod][i];
            if(F[nod][fiu]==C[nod][fiu]||VIZ[fiu])
                continue;
            VIZ[fiu]=1;
            PAR[fiu]=nod;
            Q[++u]=fiu;
        }
        p++;
    }
    return VIZ[dest];
}
void maxflow()
{
    int fmin,i,nod,x;
    while(BFS())
    {
        for(size_t i=0;i<G[dest].size();i++)
        {
            nod=G[dest][i];
            fmin=INF;
            if(C[nod][dest]==F[nod][dest]||!VIZ[nod])
                continue;
            PAR[dest]=nod;
            for(nod=dest;nod!=source;nod=PAR[nod])
                fmin=min(fmin,C[PAR[nod]][nod]-F[PAR[nod]][nod]);
            if(fmin==0)
                continue;
            for(nod=dest;nod!=source;nod=PAR[nod])
            {
                F[PAR[nod]][nod]+=fmin;
                F[nod][PAR[nod]]-=fmin;
            }
        }
    }
}
void print()
{
    int i,j,nod;
    for(i=0;i<26;i++)
    {
        for(size_t j=0;j<G[i].size();j++)
        {
            nod=G[i][j];
            if(nod==source)
                continue;
            while(F[i][nod]>0)
            {
                SOL[POZ[i].back()]=B[nod/26-1][nod%26].back();
                F[i][nod]--;
                POZ[i].pop_back();
                B[nod/26-1][nod%26].pop_back();
            }
        }
    }
    for(i=1;i<=N;i++)
        fout<<SOL[i]<<' ';
}
int main()
{
    read();
    prep();
    maxflow();
    print();
    return 0;
}
