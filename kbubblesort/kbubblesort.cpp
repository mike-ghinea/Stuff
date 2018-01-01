#include<fstream>
using namespace std;
ifstream cin("kbubblesort.in");
ofstream cout("kbubblesort.out");
int n,k,v[1000001],ok,i,aux,pas,a;
int main()
{
    cin>>n>>k;
    a=n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    ok=1;
    while(n!=0)
    {
        if(pas==k)
            break;
        ok=0;
        for(i=1;i<n;i++)
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ok=i;
                pas++;
                if(pas==k)
                    break;
            }
        n=ok;
    }
    for(i=1;i<=a;i++)
        cout<<v[i]<<" ";
    return 0;
}
