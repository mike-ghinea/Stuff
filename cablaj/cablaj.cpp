#include<fstream>
#include<climits>
#include<cmath>
#include<iomanip>
#define foreach(n,i) for(int i=1;i<=n;i++)
#define N 3010
using namespace std;
ifstream cin("cablaj.in");
ofstream cout("cablaj.out");
bool viz[N];
int n,x[N],y[N],nod,v[N],val,cost;
double sol;
int dist(int a,int b)
{
    int l=x[a]-x[b];
    int c=y[a]-y[b];
    return l*l + c*c;
}
void apm(int nod)
{
    foreach(n,i)
    {
        if(i==nod)
            continue;
        cost=dist(i,nod);
        v[i]=min(v[i],cost);
    }
}
int main()
{
    cin>>n;
    foreach(n,i)
        cin>>x[i]>>y[i];
    foreach(n,i)
        v[i]=INT_MAX;
    v[1]=0;
    viz[1]=1;
    apm(1);
    foreach(n-1,i)
    {
        val=INT_MAX;
        foreach(n,j)
        {
            if(val>v[j] and viz[j]==0)
            {
                val=v[j];
                nod=j;
            }
        }
        apm(nod);
        viz[nod]=1;
        sol+=sqrt(v[nod]);
    }
    cout<<fixed<<setprecision(3)<<sol;
    return 0;
}
