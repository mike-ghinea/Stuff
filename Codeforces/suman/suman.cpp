#include<fstream>
using namespace std;
ifstream cin("suman.in");
ofstream cout("suman.out");
int v[21],N,k,X[21];
long long SOL,cmmmc;
inline int euclid(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
void solve(int niv)
{
    for(int i=X[niv-1]+1;i<=k;++i)
    {
        X[niv]=i;
        int aux=cmmmc;
        int cmmdc=euclid(cmmmc,v[i]);
        cmmmc*=1ll*v[i]/cmmdc;
        long long NR=N/cmmmc;
        if(niv%2)
            SOL+=1ll*(NR*(NR+1)/2)*cmmmc;
        else
            SOL-=1ll*(NR*(NR+1)/2)*cmmmc;
        if(niv<k and cmmmc<=N)
            solve(niv+1);
        cmmmc=aux;
    }
}
int main()
{
    cin>>N;
    cin>>k;
    int i;
    cmmmc=1;
    for(i=1;i<=k;++i)
        cin>>v[i];
    solve(1);
    cout<<SOL;
}
