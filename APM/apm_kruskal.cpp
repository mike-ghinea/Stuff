//KRUSKAL
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream cin("apm.in");
ofstream cout("apm.out");
const int MDIM = 400001;
const int NDIM = 200001;
int A[MDIM][3],POS[MDIM],V[MDIM],G[NDIM];
bool cmp(int i,int j)
{
    return A[i][2]<A[j][2];
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
    int i,N,M;
    cin>>N>>M;
    for(i=1;i<=M;++i)
    {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
        POS[i]=i;
    }
    int counter=0,sol=0;
    memset(G,-1,sizeof(G));
    sort(POS+1,POS+M+1,cmp);
    for(i=1;i<=M;++i)
    {
        int aux=POS[i];
        int &X=A[aux][0];
        int &Y=A[aux][1];
        if(pmd(X)!=pmd(Y))
        {
            sol+=A[aux][2];
            G[pmd(X)]=pmd(Y);
            V[++counter]=aux;
        }
    }
    cout<<sol<<"\n"<<N-1<<"\n";
    for(i=1;i<=N-1;i++)
        cout<<A[V[i]][0]<<" "<<A[V[i]][1]<<"\n";
}
