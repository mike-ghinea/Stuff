#include<fstream>
using namespace std;
ifstream cin("arbint.in");
ofstream cout("arbint.out");
int maxarb[4*100001+5],pos,val,a,b,n,m,i,Max,st,dr,start,fin,x;
bool p;
void up(int nod,int st ,int dr)
{
    if(st==dr)
    {
        maxarb[nod]=val;
        return;
    }
    int mij=(st+dr)/2;
    if(pos<=mij)
        up(2*nod,st,mij);
    else
        up(2*nod+1,mij+1,dr);
    maxarb[nod]=max(maxarb[2*nod],maxarb[2*nod+1]);
}
void q(int nod,int st,int dr)
{
    if(start<=st&&dr<=fin)
    {
        Max=max(Max,maxarb[nod]);
        return;
    }
    int mij = (st+dr)/2;
    if (start<=mij)
        q(2*nod,st,mij);
    if (mij<fin)
        q(2*nod+1,mij+1,dr);
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        val=x;
        pos=i;
        up(1,1,n);
    }
    for(i=1;i<=m;i++)
    {
        cin>>p>>a>>b;
        if(p==0)
        {
            Max=-1;
            start=a;
            fin=b;
            q(1,1,n);
            cout<<Max<<"\n";
        }
        else
        {
            pos=a;
            val=b;
            up(1,1,n);
        }
    }
    return 0;
}

