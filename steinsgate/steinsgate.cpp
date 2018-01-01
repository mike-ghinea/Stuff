#include<fstream>
#include<vector>
#include<cstring>
#define NDIM 21
#define pb push_back
using namespace std;
ifstream cin("steinsgate.in");
ofstream cout("steinsgate.out");
int N,M,K,i,v[NDIM],x,y,m[NDIM],k,j;
vector <int> G[NDIM];
int main()
{

    for(i=0;i<=20;i++)
        v[i] = i;
    memset(v,0,NDIM);
    for(i=1;i<=20;i++)
        cout<<v[i]<<" ";
}
