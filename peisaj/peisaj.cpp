#include<fstream>
#include<cstring>
#define abs(x) x<0?-x:x
using namespace std;
ifstream cin("peisaj.in");
ofstream cout("peisaj.out");
long long d[51][51],n,k,i,j,sol2,D[51][51];
int main()
{
    cin>>n>>k;
    d[1][1]=1;
    for(j=1;j<n;j++)
        for(i=0;i<=n;i++)
        {
            d[i+1][j+1]+=d[i][j];
            if(i>0)
                d[i-1][j+1]+=d[i][j];
        }
    memcpy(D[k],d[k],sizeof(D[k]));
    for(j=k;j<n;j++)
        for(i=0;i<=k;i++)
        {
            if(i+1<k)
                D[i+1][j+1]+=D[i][j];
            if(i>0)
                D[i-1][j+1]+=D[i][j];
        }
    cout<<d[0][n]<<" "<<D[0][n]<<" 0\n";
}
