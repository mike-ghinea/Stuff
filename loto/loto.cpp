#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("loto.in");
ofstream cout("loto.out");
struct elem{
    int a;
    int n1,n2,n3;
}v[1000001];
int cmp(elem x,elem y)
{
    return x.a<y.a;
}
int nr,n,s,a[101],i,j,k,st,dr,ok,mij;
int main()
{
    cin>>n>>s;
    for(i=1;i<=n;i++)
        cin>>a[i];
    nr=0;
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            for(k=j;k<=n;k++)
            {
                nr++;
                v[nr].a=a[i]+a[j]+a[k];
                v[nr].n1=i;
                v[nr].n2=j;
                v[nr].n3=k;
            }
    sort(v+1,v+nr+1,cmp);
    ok=1;
    for(i=1;i<=nr and ok==1;i++){
        k=s-v[i].a;
        st=1;dr=nr;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(k>v[mij].a)
                st=mij+1;
            else if(k<v[mij].a)
                dr=mij-1;
            else
            {
                ok=0;
                cout<<a[v[i].n1]<<" "<<a[v[i].n2]<<" "<<a[v[i].n3]<<" "<<a[v[mij].n1]<<" "<<a[v[mij].n2]<<" "<<a[v[mij].n3];
                break;
            }
        }
    }
if(ok==1)
    cout<<-1;
    return 0;
}
