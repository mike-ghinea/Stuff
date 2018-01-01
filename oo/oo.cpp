#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("oo.in");
ofstream cout("oo.out");
int n,v[100011],i,oo[100011],Max=-1;
int max(int a,int b){
    if(a>b) return a;
    return b;
}
void get_max(int i,int n)
{
    int k;
    for (k=i;k<=n;k++)
    {
        oo[k]=max(oo[k-1], oo[k-3]+v[k]+v[k-1]);
        if (Max < oo[k])
            Max = oo[k];
    }
    memset(oo, 0, sizeof(oo));
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    v[n+1]=v[1];
    oo[2]=v[1]+v[2];
    get_max(3,n-1);
    oo[3]=v[2]+v[3];
    get_max(4,n);
    oo[4]=v[3]+v[4];
    get_max(5,n+1);
    cout<<Max;
    return 0;
}
