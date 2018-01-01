#include<fstream>
#include<climits>
#define inf INT_MAX
#define DIM 1<<21
using namespace std;
ifstream cin("boom.in");
ofstream cout("boom.out");
int D[DIM][3],c[51*DIM],N,n,M,v[51],cost[51],i,j,a,u,x,p,y,z,nou;
void rec(int poz,int suv)
{
    if(poz==n)
    {
        cout<<suv<<"\n";
        return;
    }
    rec(D[poz][1],suv+1);
    cout<<D[poz][2]<<"\n";
}
int main()
{
    cin>>N>>M;
    n=(1<<N)-1;
    for(i=0;i<=n;i++)
        D[i][0]=inf;
    for(i=1;i<=M;i++)
    {
        cin>>cost[i]>>x;
        for(j=1;j<=x;j++)
        {
            cin>>a;
            v[i]+=(1<<(a-1));
        }
    }
    D[n][0]=0;
    c[++u]=n;
    p=1;
    while(p<=u)
    {
        for(i=1;i<=M;i++)
        {
            x=(c[p] xor v[i]) & c[p];
            y=x*2;
            if(y>n)
                y-=(1<<N);
            z=x/2;
            nou = y | z;
            if(D[nou][0]>D[c[p]][0]+cost[i])
            {
                D[nou][0]=D[c[p]][0]+cost[i];
                D[nou][1]=c[p];
                D[nou][2]=i;
                c[++u]=nou;
            }
        }
        p++;
    }
    cout<<D[0][0]<<"\n";
    rec(0,0);
    return 0;
}
