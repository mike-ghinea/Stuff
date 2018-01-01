#include<fstream>
using namespace std;
ifstream cin("gfact.in");
ofstream cout("gfact.out");
long long n,k,v[50001],p[50001],nr,i,st,dr,mij,q,w,ok;
int main()
{
    cin>>n>>k;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v[++nr]=i;
            while(n%i==0)
            p[nr]+=k,n/=i;
        }
    }
    if(n!=1)
    {
        v[++nr]=n;
        p[nr]=k;
    }
    st=1;dr=40000000000001;
    while(st<=dr)
    {
        ok=0;
        mij=st+(dr-st)/2;
        for(i=1;i<=nr;i++)
        {
            q=0;w=v[i];
            while(mij/w!=0)
                q+=mij/w,w*=v[i];
            if(q<p[i])
            {
                ok=1;
                break;
            }
        }
        if(ok==1)
            st=mij+1;
        else
            dr=mij-1;
    }
    cout<<st;
    return 0;
}
