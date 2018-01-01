#include<fstream>
#define mod 2000003
using namespace std;
ifstream cin("sandokan.in");
ofstream cout("sandokan.out");
int n,k,s,v[5001],i,j;
int main(){
    cin>>n>>k;
    s=n%(k-1);
    if(s==0)
        s=k-1;
    s--;
    v[0]=1;
    for(i=1;i<n;i++)
        for(j=i;j>0;j--)
            v[j]=(v[j]+v[j-1])%mod;
    cout<<v[s];
    return 0;
}
