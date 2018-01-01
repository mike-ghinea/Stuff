#include <fstream>
using namespace std;
ifstream cin("permlcs.in");
ofstream cout("permlcs.out");
int a[11][1001],i,N,j,k,d[1001],M,v[1001],Max;
int main()
{
    cin>>N>>M;
    d[1]=1;
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
        {
            cin>>v[j];
            a[i][v[j]]=j;
        }
    bool ok;
    for(i=2;i<=N;i++)
    {
        d[i]=1;
        for(j=1;j<i;j++)
        {
            ok=0;
            for(k=1;k<=M;k++)
                if(a[k][v[i]]<a[k][v[j]])
                {
                    ok=1;
                    break;
                }
            if(!ok and d[i]<d[j]+1)
                d[i]=d[j]+1;
        }
    }
    for(i=1;i<=N;i++)
        Max=max(d[i],Max);
    cout<<Max;
    return 0;
}
