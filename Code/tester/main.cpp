#include <fstream>
#include <vector>
#include <stack>

#define mkp make_pair
#define R 5001
#define pb push_back
#define Ndim 502
#define Mdim 5002
using namespace std;
ifstream fin("tester.in");
ofstream fout("tester.out");
int N,M,nr,GIN[Mdim],GOUT[Mdim],PATH[Ndim*Mdim*2],T[Mdim][2];
vector < pair <int,int> > A[Ndim];
vector <int> G[Mdim];
stack <int> STV;
void read()
{
    int i,a,b;
    fin>>N>>M;
    for(i=1;i<=M;i++)
    {
        fin>>a>>b;
        T[i][0]=a;T[i][1]=b;
        A[a].pb(mkp(b,i));
    }
}
void prep()
{
    int i,nod1,nod2;
    for(i=1;i<=N;i++)
    {
        for(size_t j=0;j<A[i].size();j++)
        {
            for(size_t k=0;k<A[A[i][j].first].size();k++)
            {
                nod1=A[i][j].second;
                nod2=A[A[i][j].first][k].second;
                G[nod1].pb(nod2);
                GIN[nod2]++;
                GOUT[nod1]++;
            }
        }
    }
    for(i=1;i<=M;i++)
    {
        while(GIN[i]<GOUT[i])
        {
            G[R].pb(i);
            GIN[i]++;
            GOUT[R]++;
        }
        while(GOUT[i]<GIN[i])
        {
            G[i].pb(R);
            GOUT[i]++;
            GIN[R]++;
        }
    }
}
void euler(int nod)
{
    int nou;
    STV.push(nod);
    while(!STV.empty())
    {
        nod = STV.top();
        if(G[nod].size())
        {
            nou = G[nod].back();
            STV.push(nou);
            G[nod].pop_back();
        }
        else
        {
            PATH[++nr]=nod;
            STV.pop();
        }
    }
}
void print()
{
    bool OK=1;
    for(int i=nr-1;i>1;i--)
    {
        if(OK==1)
        {
            fout<<T[PATH[i]][0]<<' '<<T[PATH[i]][1]<<' ';
            OK=0;
        }
        else
        {
            if(PATH[i]==R)
            {
                OK=1;
                fout<<"R ";
            }
            else
                fout<<T[PATH[i]][1]<<' ';
        }
    }
}
int main()
{
    read();
    prep();
    euler(R);
    print();
    return 0;
}
