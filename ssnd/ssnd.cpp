#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("ssnd.in");
ofstream cout("ssnd.out");
int prim[10000],n=21,i,j;
int ciur(int n){
    for(i=1;i<=n;i++)
        prim[i]=1;
    for(i=2;i<=n;i++)
        if(prim[i]==1)
        {
            for(j=i+i;j<=n;j+=i)
            prim[j]=0;
        }
}
int sum(int k,int x,int n){
    ciur(k);
    for(i=2;i<=x;i++)
    {
        if(prim[i]==1)

    }
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        ciur(k);
        d=k;
        /
        sum(k);
        prod(k);
    }
}
