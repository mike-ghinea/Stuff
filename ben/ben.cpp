#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("ben.in");
ofstream cout("ben.out");
int N,i,A[30003],Max=0,sum[30003],sol,nrpos,nrp,nrv,a,b;
struct vid{int x;int y;}v[30003];
int cmp(vid o, vid p)
{
    return o.x<p.x;
}
int main()
{
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>a>>b;
        v[++nrv].x=a;
        v[nrv].y=1;
        v[++nrv].x=b;
        A[a]++;
        A[b+1]--;
        Max=max(Max,b);
    }
    for(i=1;i<=Max;i++)
    {
        sum[i]=sum[i-1]+A[i];
        sol=max(sol,sum[i]);
    }
    sort(v+1,v+nrv+1,cmp);
    nrp=sol;
    nrpos=1;
    for(i=1;i<=nrv;i++)
    {

        if(v[i].y==1)
        {
            if(nrp!=0)
                nrpos=nrpos*nrp%32173;
            nrp--;
        }
        else
            nrp++;
    }
    cout<<sol<<' '<<nrpos;
    return 0;
}
